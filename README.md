# Relatório do Código de Sistema Bancário
## Introdução

Este programa implementa um sistema bancário simples em C++. Ele fornece funcionalidades básicas como criar uma conta, fazer login, exibir informações da conta, transferir dinheiro e listar todas as contas (apenas para admin). O código está organizado em classes e utiliza estruturas de dados como listas.
Estrutura do Código
Classes

* Account: Representa uma conta bancária com atributos como nome, email, número de telefone, localização e saldo.

* List: Implementa uma lista genérica para armazenar contas.

* Manager: Contém métodos para gerenciar contas, como adicionar, verificar a existência e obter informações de uma conta.

## Fluxo de Execução

* main(): Inicia o programa chamando a função welcome().
* welcome(): Apresenta as opções para criar uma conta ou fazer login e chama a função sign() para processar a escolha do usuário.
* sign(bool mode): Cria uma nova conta ou faz login com base no modo fornecido. Após a criação ou login bem-sucedido, chama a função menu().
* menu(): Apresenta opções de operação da conta, como exibir informações, transferir dinheiro ou listar todas as contas.
* O programa continua a executar o menu até que o usuário escolha sair.

## Operações Principais
1. Criar Conta

    Solicita informações como nome, email, número de telefone, localização e senha.
    Cria uma instância da classe Account e adiciona à lista de contas.

2. Login

    Solicita identificação (email ou número de telefone) e senha.
    Verifica a existência da conta com base nas credenciais fornecidas.
    Se o login for bem-sucedido, armazena a conta atual e chama o menu().

3. Exibir Informações da Conta

    Apresenta detalhes como ID, dono, email, telefone, localização e saldo da conta.

4. Transferir Dinheiro

    Solicita o número da conta do destinatário e a quantidade a ser transferida.
    Verifica a existência da conta do destinatário e a disponibilidade de saldo.
    Efetua a transferência, atualizando os saldos das contas envolvidas.

5. Listar Todas as Contas (Admin)

    Lista todas as contas e seus saldos.

## Conclusão

O código fornece uma implementação funcional de um sistema bancário simples em C++. Pode ser estendido e aprimorado com recursos adicionais, como segurança aprimorada, histórico de transações e interface gráfica. O uso de classes e estruturas de dados ajuda a organizar o código de maneira eficiente. Este relatório serve como uma introdução ao funcionamento e estrutura geral do programa.