import pandas as pd
dic = {'student' : ['Kartik','hemant','milind'] , 'cspa' : [9.8,10,2.3]}
pf = pd.DataFrame(dic)
print(pf) 
print(pf['cspa'].values)
