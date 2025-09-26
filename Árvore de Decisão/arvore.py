import os
import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn import tree

os.system('cls')

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

traducao_classes = {
    1: "Mamífero",
    2: "Ave",
    3: "Réptil",
    4: "Peixe",
    5: "Anfíbio",
    6: "Inseto",
    7: "Invertebrado"
}

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

dados = pd.read_csv("zoo.csv")

dados.rename(columns=traducao_colunas, inplace=True)

dados["tipo_classe"] = dados["tipo_classe"].map(traducao_classes)
dados["nome_animal"] = dados["nome_animal"].map(traducao_animais)

print(dados.head())

caracteristicas = dados.drop(["nome_animal", "tipo_classe"], axis = 1)
classe = dados["tipo_classe"]

nomes_animais = dados["nome_animal"]

carac_treino, carac_teste, classe_treino, classe_teste, nomes_treino, nomes_teste = train_test_split(
    caracteristicas, classe, nomes_animais, test_size=0.2, random_state=1, stratify=classe
)

arvore = DecisionTreeClassifier()
arvore.fit(carac_treino, classe_treino)

classe_prevista = arvore.predict(carac_teste)

precisao = accuracy_score(classe_teste, classe_prevista)

print(f'\nPrecisão do modelo: {precisao * 100:.2f}%\n')

texto_arvore = tree.export_text(arvore, feature_names=list(caracteristicas.columns))

texto_arvore = texto_arvore.replace("<= 0.50", "= NÃO")
texto_arvore = texto_arvore.replace(">  0.50", "= SIM")

print("Regras aprendidas pela árvore:\n")
print(texto_arvore)

resultado = pd.DataFrame({
    "animal": nomes_teste.values,
    "classe real": classe_teste.values,
    "classe prevista": classe_prevista
})

print("\nResultados da classificação no conjunto de teste:\n")
print(resultado)