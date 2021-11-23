from utils.format import Format

# answer mask format
senior_af = Format(SX=133, SY=459, W=517, H=1074,
                   ROW=40, COL=2, TOT=80, LEN=436, N=12,
                   BW=30, BH=10,
                   THRES=50, DICT=['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'])

# id mask format
senior_idf = Format(SX=133, SY=127, W=0, H=140,
                    ROW=6, COL=1, TOT=6, LEN=357, N=10,
                    BW=30, BH=10,
                    THRES=50, DICT=['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'])

senior_fmts = {"answer_format": senior_af,
               "id_format": senior_idf}

# ==================================================================================================

# answer mask format
junior_af = Format(SX=184, SY=774, W=717, H=747,
                   ROW=20, COL=4, TOT=80, LEN=121, N=4,
                   BW=25, BH=25,
                   THRES=100, DICT=['A', 'B', 'C', 'D', 'E'])

# id mask format
junior_idf = Format(SX=226, SY=340, W=0, H=197,
                    ROW=6, COL=1, TOT=6, LEN=357, N=10,
                    BW=25, BH=25,
                    THRES=100, DICT=['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'])

junior_fmts = {"answer_format": junior_af,
               "id_format": junior_idf}

# ==================================================================================================

formats = {"junior": junior_fmts,
           "senior": senior_fmts}
