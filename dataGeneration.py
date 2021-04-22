import pandas as pd
import numpy as np

df1=pd.DataFrame(np.random.randint(0,900,size=(2,25000)))
df2=pd.DataFrame(np.random.randint(900,1500,size=(2,25000)))

df3= pd.concat([df1,df2], axis=1, ignore_index=True)

print(df1)

print(df2)

print(df3)

df3.to_csv('dsB.csv',header=False)
