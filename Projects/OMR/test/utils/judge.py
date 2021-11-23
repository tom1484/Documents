from numpy import array, zeros, empty

from pandas import ExcelFile, read_excel

from utils.answer import Answer


class Judge(object):

    def __init__(self, fmt):
        self.binToSym = fmt.DICT
        self.symToBin = {}

        for (i, v) in enumerate(fmt.DICT):
            self.symToBin[v] = i

        self.binLength = len(fmt.DICT)

    def judge(self, binaries):
        scores = zeros(binaries.shape[0])

        for i in range(self.judge_start, self.judge_end):

            b = binaries[i]

            ans = self.answers[i]
            if ans is None:
                scores[i] = 0
                continue

            # ==================================================================================================

            config = self.configs.iloc[ans.config_id]

            wrong = 0
            select = 0
            scores[i] = config['總分']

            for (j, v) in enumerate(b):
                if v == 1:
                    select += 1
                if v != self.answers[i].binary[j]:
                    wrong += 1

            if config['單/多'] == '多':
                punish = wrong * config['單項扣分']
                punish = min(punish, config['扣分上限'])

                if select != 0:
                    scores[i] -= punish
                else:
                    scores[i] = 0
            else:
                if wrong > 0:
                    scores[i] = 0

        return scores

    def get_binary(self, symbol):
        res = [0] * self.binLength
        for s in symbol:
            res[self.symToBin[s]] = 1

        return array(res, dtype=int)

    def read_answer(self, path):
        # read file information
        excel = ExcelFile(path)
        # read answers and remove the column of number
        answers = read_excel(path, sheet_name=excel.sheet_names[0])
        answers = answers.drop(columns=[answers.columns[0]])
        # read configs
        configs = read_excel(path, sheet_name=excel.sheet_names[1])
        self.configs = configs

        excel.close()

        # build array of config id of answers
        config_ids = zeros(answers.shape[0], dtype=int)

        # ==================================================================================================

        # judge range
        judge_start = answers.shape[0]
        judge_end = 0

        for i, row in configs.iterrows():
            start, end = row['起始'], row['結尾']
            for j in range(start - 1, end):
                config_ids[j] = i

            judge_start = min(judge_start, start - 1)
            judge_end = max(judge_end, end)

        self.judge_start = judge_start
        self.judge_end = judge_end

        # ==================================================================================================

        # build array of answers
        results = empty(answers.shape[0], dtype=object)

        for i, row in answers.iterrows():
            symbol = row['答案']
            if type(symbol) != str:
                continue
            # pack into Answer
            results[i] = Answer(symbol,
                                self.get_binary(symbol), config_ids[i])

        self.answers = results

        return self.judge_start, self.judge_end
