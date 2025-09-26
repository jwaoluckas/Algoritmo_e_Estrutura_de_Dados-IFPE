import os
import random

os.system('cls')

qtd_descend = random.randint(1, 1000)
portas = []

for i in range(qtd_descend):
    portas.append('fechada')

num = 1

for i in range(qtd_descend):
    for n in range(num, qtd_descend+1):
        if(n % num == 0):
            if(portas[n-1] == 'fechada'):
                portas[n-1] = 'aberta'

            else:
                portas[n-1] = 'fechada'

    for x in range(num):
        if(portas[x] == 'aberta'):
            print(x+1, end=' ')

    print('\n')

    num += 1