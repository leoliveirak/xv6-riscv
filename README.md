# Trabalho de Sistemas Operacionais

## Alunos  
- **Gustavo Botezini** (2311100062)  
- **Leonardo de Oliveira Klitzke** (2311100019)  

## Nome do Trabalho  
**Escalonamento de Processos com Bilhetes no xv6**  

## Instruções de Compilação  

Para compilar o projeto, execute:  
```sh
make
```
Para rodar no emulador QEMU, use:  
```sh
make qemu
```

## Comandos de testes  

### Testar `testeprofessor`  
Teste final para observar processos com mais prioridade terminando antes  
```sh
testeprofessor
```


## Descrição do Projeto  
Este projeto implementa o gerenciamento de processos utilizando um sistema de bilhetes para controle da execução. Cada processo recebe um número de bilhete que pode influenciar na ordem de execução dentro do sistema.  
