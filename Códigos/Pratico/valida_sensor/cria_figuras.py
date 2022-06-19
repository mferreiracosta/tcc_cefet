import pandas as pd
import matplotlib.pyplot as plt

# Criação de um DataFrame vazio
data = pd.DataFrame()

# Criação de um DataFrame através do arquivo .txt
df = pd.read_csv(
    'grava_dados/data_v2.txt', sep="\n", header=None)

# Tratamento dos dados da base de dados
valores = df[0].str.split("|", n=1, expand=True)

# Preenchimento do DataFrama data
data["kalman"] = pd.to_numeric(valores[0], errors='coerce')
data["pitch"] = pd.to_numeric(valores[1], errors='coerce')
data["pontos"] = list(range(len(data)))

# Plot da figura com todos os valores
plt.plot(data['kalman'].loc[0:1500], 'b-', label='kalmanY')
plt.plot(data['pitch'].loc[0:1500], 'r--', label='pitch')
plt.xlabel("Pontos")
plt.ylabel("Graus (º)")
plt.title("Sinais do Sensor - Amostra B")
plt.legend()
plt.show()

# Plot de uma pequena amostra da figura
plt.plot(data['kalman'].loc[1050:1200], 'b-', label='kalmanY')
plt.plot(data['pitch'].loc[1050:1200], 'r--', label='pitch')
plt.xlabel("Pontos")
plt.ylabel("Graus (º)")
plt.title("Fatia dos Sinais - Amostra B")
plt.legend()
plt.show()