import json
import os

data_sir = 'D:/PythonProject/data'
arr = []
count = 0
for name in os.listdir(data_sir):
    if name.endswith('.json'):
        with open(os.path.join(data_sir, name), 'r', encoding='utf-8') as file:
            rec = json.load(file)
            if rec['Название'] not in arr and rec['Название'] != 'None inf':
                arr.append(rec['Название'])
            else:
                count+=1
                print(count, rec['Название'])