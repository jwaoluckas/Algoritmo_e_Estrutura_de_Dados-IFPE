import os

os.system('cls')

portas = []

for i in range(4):
    portas.append('fechada')

num = 1

for i in range(4):
    for i in range(num, 5):
        if(i % num == 0):
            if(portas[i-1] == 'fechada'):
                portas[i-1] = 'aberta'

            else:
                portas[i-1] = 'fechada'

    num += 1
        
print(portas)

num = 1

for i in range(4):
    portas_abertas = 0

    for n in range(num):
        if(portas[n] == 'aberta'):
            portas_abertas += 1

            if(portas_abertas <= 1):
                print(n+1)

            else:
                print(end=' ')
                print(n+1)

    num += 1