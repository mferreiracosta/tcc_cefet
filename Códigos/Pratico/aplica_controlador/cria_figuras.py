import pandas as pd
import matplotlib.pyplot as plt

# Criação de um DataFrame vazio
data = pd.DataFrame()

# Criação de um DataFrame através do arquivo .txt
df = pd.read_csv(
    'grava_dados/dadosControlador.txt', sep="\n", header=None)

# Tratamento dos dados da base de dados
valores = df[0].str.split("\t", n=1, expand=True)

print(valores)


# Preenchimento do DataFrama data
data["pwm"] = pd.to_numeric(valores[0], errors='coerce')
data["kalman"] = pd.to_numeric(valores[1], errors='coerce')
data["pontos"] = list(range(len(data)))

# Plot da figura com todos os valores
plt.plot(data['kalman'].loc[100:600], 'b-', label='kalmanY')
plt.xlabel("Pontos")
plt.ylabel("Graus (º)")
plt.title("Resposta da Planta com Controlador")
#plt.legend()
plt.show()

# Plot de uma pequena amostra da figura
plt.plot(data['pwm'].loc[100:600], 'r--', label='pwm')
plt.xlabel("Pontos")
plt.ylabel("PWM")
plt.title("Sinal de Controle")
#plt.legend()
plt.show()
