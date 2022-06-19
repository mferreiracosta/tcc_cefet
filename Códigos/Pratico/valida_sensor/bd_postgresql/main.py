import pandas as pd
import matplotlib.pyplot as plt
import psycopg2

def conecta_db():
    con = psycopg2.connect(host='localhost',
                           database='db_sinais',
                           user='postgres',
                           password='123456')
    return con

def consulta_db(sql):
    con = conecta_db()
    cur = con.cursor()
    cur.execute(sql)
    recset = cur.fetchall()
    registros = []
    for rec in recset:
        registros.append(rec)
    con.close()
    return registros

reg = consulta_db('select id, tempo, vl_kalman, vl_pitch from public.sinais')

df = pd.DataFrame(reg, columns=['id','tempo','vl_kalman','vl_pitch'])

df.info()

df['vl_kalman'] = pd.to_numeric(df['vl_kalman'], errors = 'coerce')
df['vl_pitch'] = pd.to_numeric(df['vl_pitch'], errors = 'coerce')

df.info()

df = df.loc[0:200]

kalman = df['vl_kalman']
pitch = df['vl_pitch']

plt.plot(kalman, 'g-')
plt.plot(pitch, 'b-')
plt.show()