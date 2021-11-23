import pandas as pd
import json

#data = pd.read_csv('data.csv')
#
#dicts = {}
#col_name = list(data.columns)[:3]
#for i in range(len(data)):
#    d = dicts
#    for col in col_name:
#        val = data.loc[i][col]
#        if val not in d.keys():
#            d[val] = {}
#        d = d[val]
#    d['data'] = list(data.loc[i])
#
#js = json.dumps(dicts)
#with open('data_json.txt', 'w') as json_file:
#  json.dump(dicts, json_file)

with open('data_json.txt', 'r') as json_file:
  data = json.loads(json_file.read())

find = pd.read_csv('to_find.csv').loc
cols = ['School', 'Last Name']

res = []
for i in range(len(find[:])):
    find_data = find[i]
    first_name = find[i]['First Name']
    
    p_data = None
    count = 0
    matches = data
    for col in cols:
        val = find_data[col]
        if val in matches.keys():
            matches = matches[val]
            count += 1
        else:
            break
    
    if count < len(cols):
        continue
    
    for key in matches.keys():
        if (len(key) == 2 and len(first_name) == 2 and key[1] == first_name[1]) or \
           (len(key) == 1 and len(first_name) == 1):
            match = matches[key]['data']
            p_data = (match[0], match[1] + match[2], match[5], match[7])

    res.append(p_data)

out = open('out.txt', 'w+', encoding='utf-8')

for p_data in res:
    if p_data != None:
        s = f'{p_data[0]},{p_data[1]},{p_data[2]},{p_data[3]}\n'
    else:
        s = 'None'
    out.write(str(s.encode('utf-8').decode('utf-8')))

out.close()





