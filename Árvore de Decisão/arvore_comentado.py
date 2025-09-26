# ===================================================================================
# SEÇÃO 1: IMPORTAÇÃO DAS BIBLIOTECAS
# Bibliotecas são conjuntos de ferramentas e funções pré-prontas que podemos usar.
# ===================================================================================

# 'os' (Operating System) é uma biblioteca que permite interagir com o sistema operacional.
# Usaremos ela para executar um comando que limpa a tela do terminal.
import os

# 'pandas' é a principal biblioteca em Python para manipulação e análise de dados.
# Ela nos permite trabalhar com tabelas (que ela chama de DataFrames) de forma muito eficiente.
# 'as pd' é um "apelido" padrão que a comunidade Python usa para o pandas, para não precisar escrever "pandas" toda vez.
import pandas as pd

# Da biblioteca 'scikit-learn' (sklearn), que é focada em Machine Learning...
# ...do módulo 'tree' (que contém algoritmos de árvore)...
# ...importamos a classe 'DecisionTreeClassifier', que é o nosso modelo de Árvore de Decisão para problemas de classificação.
from sklearn.tree import DecisionTreeClassifier

# Da biblioteca 'scikit-learn', do módulo 'model_selection' (que ajuda a validar modelos)...
# ...importamos a função 'train_test_split'. Ela serve para dividir nossos dados em um conjunto de treino e um de teste.
from sklearn.model_selection import train_test_split

# Da biblioteca 'scikit-learn', do módulo 'metrics' (que calcula métricas de performance)...
# ...importamos a função 'accuracy_score'. Ela calcula a precisão (acurácia) do nosso modelo.
from sklearn.metrics import accuracy_score

# Da biblioteca 'scikit-learn', importamos o módulo 'tree' inteiro.
# Faremos isso para usar uma função específica dele, a 'export_text', que "desenha" a árvore em formato de texto.
from sklearn import tree

# ===================================================================================
# SEÇÃO 2: PREPARAÇÃO DO AMBIENTE E DOS DADOS
# ===================================================================================

# Utiliza a biblioteca 'os' para executar um comando diretamente no terminal do seu computador.
# 'cls' é o comando para limpar a tela do terminal no sistema operacional Windows.
# Se estivesse em Linux ou macOS, o comando seria 'clear'.
os.system('cls')

# Aqui criamos um "dicionário" Python. Dicionários guardam dados no formato "chave: valor".
# Este dicionário servirá como um "mapa de tradução" para os nomes das colunas da nossa tabela.
# A chave (à esquerda) é o nome original em inglês, e o valor (à direita) é a tradução para português.
traducao_colunas = {
    "animal_name": "nome_animal",
    "hair": "tem_pelos",
    "feathers": "tem_penas",
    "eggs": "poe_ovos",
    "milk": "da_leite",
    "airborne": "voa",
    "aquatic": "aquatico",
    "predator": "predador",
    "toothed": "tem_dentes",
    "backbone": "tem_coluna",
    "breathes": "respira",
    "venomous": "venenoso",
    "fins": "tem_barbatanas",
    "legs": "quantidade_patas",
    "tail": "tem_rabo",
    "domestic": "domestico",
    "catsize": "tamanho_gato",
    "class_type": "tipo_classe"
}

# Criamos um segundo dicionário para traduzir os números da coluna "class_type".
# O arquivo original usa números (1 a 7) para representar as classes dos animais.
# Este dicionário mapeia cada número (chave) para o seu nome correspondente em texto (valor).
traducao_classes = {
    1: "Mamífero",
    2: "Ave",
    3: "Réptil",
    4: "Peixe",
    5: "Anfíbio",
    6: "Inseto",
    7: "Invertebrado"
}

# Criamos um terceiro dicionário, agora para traduzir o nome de cada animal para português.
# A lógica é a mesma: a chave é o nome em inglês, o valor é o nome em português.
traducao_animais = {
    "aardvark": "porco-formigueiro", "antelope": "antílope", "bass": "robalo", "bear": "urso", "boar": "javali", "buffalo": "búfalo",
    "calf": "bezerro", "carp": "carpa", "catfish": "peixe-gato", "cavy": "preá", "cheetah": "guepardo", "chicken": "galinha",
    "chub": "peixe-branco", "clam": "marisco", "crab": "caranguejo", "crayfish": "lagostim", "crow": "corvo", "deer": "veado",
    "dogfish": "tubarão-cão", "dolphin": "golfinho", "dove": "pomba", "duck": "pato", "elephant": "elefante", "flamingo": "flamingo",
    "flea": "pulga", "frog": "rã", "fruitbat": "morcego-da-fruta", "giraffe": "girafa", "girl": "humano (menina)", "gnat": "mosquito",
    "goat": "cabra", "gorilla": "gorila", "gull": "gaivota", "haddock": "arinca", "hamster": "hamster", "hare": "lebre",
    "hawk": "falcão", "herring": "arenque", "honeybee": "abelha", "housefly": "mosca-doméstica", "kiwi": "kiwi (ave)",
    "ladybird": "joaninha", "lark": "cotovia", "leopard": "leopardo", "lion": "leão", "lobster": "lagosta", "lynx": "lince",
    "mink": "vison", "mole": "toupeira", "mongoose": "mangusto", "moth": "mariposa", "newt": "salamandra", "octopus": "polvo",
    "opossum": "gambá", "oryx": "órix", "ostrich": "avestruz", "parakeet": "periquito", "penguin": "pinguim", "pheasant": "faisão",
    "pike": "lúcio", "piranha": "piranha", "pitviper": "víbora", "platypus": "ornitorrinco", "polecat": "toirão", "pony": "pônei",
    "porpoise": "boto", "puma": "puma", "pussycat": "gatinho", "raccoon": "guaxinim", "reindeer": "rena", "rhea": "ema",
    "scorpion": "escorpião", "seahorse": "cavalo-marinho", "seal": "foca", "sealion": "leão-marinho", "seasnake": "serpente-marinha",
    "seawasp": "vespa-do-mar", "skimmer": "talha-mar", "skua": "mandrião", "sloth": "preguiça", "slowworm": "licranço", "slug": "lesma",
    "sole": "linguado", "sparrow": "pardal", "squirrel": "esquilo", "starfish": "estrela-do-mar", "stingray": "arraia", "swan": "cisne",
    "termite": "cupim", "toad": "sapo", "tortoise": "jabuti", "tuatara": "tuatara", "tuna": "atum", "vampire": "morcego-vampiro",
    "vole": "arvícola", "vulture": "abutre", "wallaby": "wallaby", "wasp": "vespa", "wolf": "lobo", "worm": "minhoca", "wren": "carriça"
}

# Usa a função 'read_csv' da biblioteca pandas (pd) para ler o arquivo "zoo.csv".
# O conteúdo do arquivo é carregado em uma estrutura de tabela chamada DataFrame.
# Este DataFrame é armazenado na variável 'dados'.
dados = pd.read_csv("zoo.csv")

# Chama o método 'rename' do nosso DataFrame 'dados' para renomear as colunas.
# 'columns=traducao_colunas' especifica que o dicionário de tradução das colunas deve ser usado para a renomeação.
# 'inplace=True' é um parâmetro muito importante: ele diz ao pandas para modificar o DataFrame 'dados' DIRETAMENTE,
# em vez de criar uma cópia com as alterações.
dados.rename(columns=traducao_colunas, inplace=True)

# Aqui, selecionamos a coluna "tipo_classe" do nosso DataFrame.
# Em seguida, aplicamos o método 'map' a essa coluna. O 'map' usa o dicionário 'traducao_classes'
# para substituir cada valor da coluna (os números de 1 a 7) pelo seu valor correspondente no dicionário.
# O resultado (a coluna com os textos "Mamífero", "Ave", etc.) é então salvo de volta na coluna "tipo_classe".
dados["tipo_classe"] = dados["tipo_classe"].map(traducao_classes)

# Fazemos exatamente o mesmo processo da linha anterior, mas agora para a coluna "nome_animal",
# utilizando o dicionário 'traducao_animais' para traduzir os nomes dos animais.
dados["nome_animal"] = dados["nome_animal"].map(traducao_animais)

# 'print()' é a função padrão do Python para exibir informações na tela.
# '.head()' é um método de DataFrames do pandas que mostra as 5 primeiras linhas da tabela.
# É uma forma rápida de verificar se os dados foram carregados e transformados corretamente.
print(dados.head())

# ===================================================================================
# SEÇÃO 3: SEPARAÇÃO DOS DADOS PARA O MODELO DE MACHINE LEARNING
# ===================================================================================

# Aqui, estamos criando a nossa matriz de características (geralmente chamada de 'X' em Machine Learning).
# As características são os dados que o modelo usará para aprender a fazer previsões.
# 'dados.drop(...)' cria uma CÓPIA do DataFrame 'dados', mas removendo as colunas especificadas.
# ["nome_animal", "tipo_classe"] é a lista de colunas a serem removidas. Removemos porque:
#   - 'nome_animal' é apenas um identificador e não ajuda a classificar.
#   - 'tipo_classe' é a nossa RESPOSTA, o que queremos prever. Não podemos usá-la como uma pergunta.
# 'axis=1' informa ao pandas que queremos remover COLUNAS (axis=0 seria para remover linhas).
caracteristicas = dados.drop(["nome_animal", "tipo_classe"], axis = 1)

# Aqui, criamos nosso vetor de alvo (geralmente chamado de 'y').
# O alvo é a coluna de respostas corretas que o modelo deve aprender a prever.
# Simplesmente selecionamos a coluna 'tipo_classe' do DataFrame 'dados' e a guardamos na variável 'classe'.
classe = dados["tipo_classe"]

# Apenas para facilitar o acesso mais tarde, guardamos a coluna com os nomes dos animais (já traduzidos)
# em uma variável separada chamada 'nomes_animais'.
nomes_animais = dados["nome_animal"]

# Esta é uma das linhas mais importantes. Ela desempacota os resultados da função 'train_test_split'.
# A função pega os dataframes ('caracteristicas', 'classe', 'nomes_animais'), embaralha-os e os divide em dois grupos: treino e teste.
# A função retorna múltiplos dataframes, que são atribuídos às variáveis na ordem:
#   carac_treino, carac_teste, classe_treino, classe_teste, nomes_treino, nomes_teste
#
# Parâmetros da função:
#   'test_size=0.2': Define que o conjunto de TESTE terá 20% do total de dados. Consequentemente, o de TREINO terá 80%.
#   'random_state=1': Fixa a "semente" do embaralhamento. Isso garante que, toda vez que o código for executado, a divisão
#                      seja exatamente a mesma. É crucial para que os resultados sejam reprodutíveis.
#   'stratify=classe': Garante que a proporção de cada classe de animal (Mamífero, Ave, etc.) seja a mesma tanto no conjunto
#                      de treino quanto no de teste. Isso evita que, por azar, uma classe rara vá parar só em um dos conjuntos.
carac_treino, carac_teste, classe_treino, classe_teste, nomes_treino, nomes_teste = train_test_split(
    caracteristicas, classe, nomes_animais, test_size=0.2, random_state=1, stratify=classe
)

# ===================================================================================
# SEÇÃO 4: TREINAMENTO, PREVISÃO E AVALIAÇÃO DO MODELO
# ===================================================================================

# Aqui, criamos uma "instância" do nosso modelo. Pense nisso como criar um "cérebro" de Árvore de Decisão em branco,
# ainda sem nenhum conhecimento, com as configurações padrão. Este cérebro está pronto para aprender.
arvore = DecisionTreeClassifier()

# Este é o comando de TREINAMENTO. O método '.fit()' ("ajustar") é onde a mágica acontece.
# Ele pega as características de treino ('carac_treino') e as respostas corretas de treino ('classe_treino')
# e analisa esses dados para encontrar os melhores padrões e regras.
# Após esta linha, o objeto 'arvore' não está mais em branco; ele agora contém todo o conhecimento aprendido.
arvore.fit(carac_treino, classe_treino)

# Agora que o modelo está treinado, usamos o método '.predict()' ("prever") para testá-lo.
# Fornecemos a ele os dados de teste ('carac_teste'), que ele nunca viu antes.
# O modelo aplica as regras que aprendeu para "adivinhar" a classe de cada animal no conjunto de teste.
# A lista com todas as previsões é armazenada na variável 'classe_prevista'.
classe_prevista = arvore.predict(carac_teste)

# Usamos a função 'accuracy_score' que importamos para medir o quão bem o modelo se saiu.
# Ela compara a lista de respostas corretas do teste ('classe_teste') com a lista de previsões do modelo ('classe_prevista').
# O resultado é um número de 0.0 a 1.0 (ex: 0.95), que representa a porcentagem de acertos.
precisao = accuracy_score(classe_teste, classe_prevista)

# Usamos um "f-string" (o 'f' antes das aspas) para imprimir o resultado de forma formatada.
# '\n' cria uma linha em branco antes e depois da frase, para espaçamento.
# '{precisao * 100:.2f}' pega a variável 'precisao', a multiplica por 100 e a formata como um número
# de ponto flutuante (f) com exatamente duas casas decimais (.2f).
print(f'\nPrecisão do modelo: {precisao * 100:.2f}%\n')

# ===================================================================================
# SEÇÃO 5: EXIBIÇÃO DOS RESULTADOS E REGRAS
# ===================================================================================

# Usamos a função 'export_text' do módulo 'tree' para gerar uma representação em texto das regras
# que o nosso modelo 'arvore' aprendeu durante o treinamento.
# 'feature_names=list(caracteristicas.columns)' passa os nomes das nossas colunas para a função,
# para que o texto mostre "tem_pelos" em vez de um número genérico como "feature_0".
texto_arvore = tree.export_text(arvore, feature_names=list(caracteristicas.columns))

# O texto gerado pela função usa notações matemáticas. Estas duas linhas usam o método de string '.replace()'
# para tornar o texto mais amigável.
# A primeira linha substitui todo texto "<= 0.50" (que para dados binários significa Falso ou 0) por "= NÃO".
texto_arvore = texto_arvore.replace("<= 0.50", "= NÃO")

# A segunda linha substitui todo texto "> 0.50" (que significa Verdadeiro ou 1) por "= SIM".
texto_arvore = texto_arvore.replace("> 0.50", "= SIM")

# Imprime o cabeçalho e, em seguida, a variável 'texto_arvore' já com as regras traduzidas e formatadas.
print("Regras aprendidas pela árvore:\n")
print(texto_arvore)

# Para mostrar os resultados de forma organizada, criamos um novo DataFrame do pandas.
# 'pd.DataFrame({...})' constrói a tabela a partir de um dicionário.
# As chaves do dicionário ("animal", "classe_real", "classe_prevista") se tornam os nomes das colunas.
# Os valores do dicionário se tornam os dados dessas colunas.
# '.values' é usado para extrair os dados puros das Séries do pandas, garantindo alinhamento correto.
resultado = pd.DataFrame({
    "animal": nomes_teste.values,
    "classe_real": classe_teste.values,
    "classe_prevista": classe_prevista
})

# Por fim, imprime um cabeçalho e o DataFrame 'resultado' final.
# Isso nos mostra, para cada animal do conjunto de teste, qual era sua classe real e qual foi a previsão do modelo.
print("\nResultados da classificação no conjunto de teste:\n")
print(resultado)