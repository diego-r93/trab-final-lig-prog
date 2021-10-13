# Instruções sobre o Menu:

1. Inserir paciente
2. Buscar paciente
3. Exibir pacientes cadastrados
4. Sair

## Tipos de pacientes (Opção 1 do MENU):

1. scheduled
2. covid
3. emergency

## Compilação:

> Para compilar digite ```make patients``` ou ```make all```. 

> Para executar digite ```./patients```

> Para remover os arquivos objetos e o executável digite ```make clean```.

> O Compilador default é o g++. Caso queira utilizar o clang++ digite ```make all compiler=CLANG```.

> O padrão default é o C++11. Caso queira utilizar outro digite ```make all dialect=C++14``` ou ```make all dialect=C++17```.