import os
import random

os.system('cls')

num = random.randint(1, 1000)
atual_regiao = 'N'

for i in range(num):
    quantas_vezes_virar = random.randint(0, 4)

    if(quantas_vezes_virar == 0):
        break

    for i in range(quantas_vezes_virar):
        lados = ['E', 'D']
        esq_ou_dir = random.choice(lados)

        if(atual_regiao == 'N'):
            if(esq_ou_dir == 'E'):
                if(quantas_vezes_virar == 1):
                    atual_regiao = 'O'

                elif(quantas_vezes_virar == 2):
                    atual_regiao = 'S'

                elif(quantas_vezes_virar == 3):
                    atual_regiao = 'L'

                else:
                    atual_regiao = 'N'

            else:
                if(quantas_vezes_virar == 1):
                    atual_regiao = 'L'

                elif(quantas_vezes_virar == 2):
                    atual_regiao = 'S'

                elif(quantas_vezes_virar == 3):
                    atual_regiao = 'O'

                else:
                    atual_regiao = 'N'

        elif(atual_regiao == 'O'):
            if(esq_ou_dir == 'E'):
                if(quantas_vezes_virar == 1):
                    atual_regiao = 'S'

                elif(quantas_vezes_virar == 2):
                    atual_regiao = 'L'

                elif(quantas_vezes_virar == 3):
                    atual_regiao = 'N'

                else:
                    atual_regiao = 'O'

            else:
                if(quantas_vezes_virar == 1):
                    atual_regiao = 'N'

                elif(quantas_vezes_virar == 2):
                    atual_regiao = 'L'

                elif(quantas_vezes_virar == 3):
                    atual_regiao = 'S'

                else:
                    atual_regiao = 'O'

        elif(atual_regiao == 'S'):
            if(esq_ou_dir == 'E'):
                if(quantas_vezes_virar == 1):
                    atual_regiao = 'L'

                elif(quantas_vezes_virar == 2):
                    atual_regiao = 'N'

                elif(quantas_vezes_virar == 3):
                    atual_regiao = 'O'

                else:
                    atual_regiao = 'S'

            else:
                if(quantas_vezes_virar == 1):
                    atual_regiao = 'O'

                elif(quantas_vezes_virar == 2):
                    atual_regiao = 'N'

                elif(quantas_vezes_virar == 3):
                    atual_regiao = 'L'

                else:
                    atual_regiao = 'S'

        else:
            if(esq_ou_dir == 'E'):
                if(quantas_vezes_virar == 1):
                    atual_regiao = 'N'

                elif(quantas_vezes_virar == 2):
                    atual_regiao = 'O'

                elif(quantas_vezes_virar == 3):
                    atual_regiao = 'S'

                else:
                    atual_regiao = 'L'

            else:
                if(quantas_vezes_virar == 1):
                    atual_regiao = 'S'

                elif(quantas_vezes_virar == 2):
                    atual_regiao = 'O'

                elif(quantas_vezes_virar == 3):
                    atual_regiao = 'N'

                else:
                    atual_regiao = 'L'

    print(atual_regiao)