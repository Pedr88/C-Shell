# Meu Shell

Este é um shell simples desenvolvido em C. O programa implementa comandos básicos e permite a execução de comandos do sistema. Este shell suporta os comandos `exit`, `echo`, `type`, `pwd` e `cd`.

## Funcionalidades

1.  **exit**: Encerra o shell.
2.  **echo [mensagem]**: Exibe a mensagem fornecida.
3.  **type [comando]**: Identifica se um comando é um comando interno do shell ou procura pelo comando nos diretórios especificados na variável de ambiente `PATH`.
4.  **pwd**: Exibe o diretório de trabalho atual.
5.  **cd [diretório]**: Altera o diretório de trabalho para o especificado.

## Como Usar

1.  Clone o repositório:
    
    `git clone https://github.com/seu-usuario/nome-do-repositorio.git`
    
2.  Compile o código:
    
    `gcc -o meu_shell meu_shell.c`
    
3.  Execute o programa:
    
    `./meu_shell`
    
4.  Digite os comandos desejados:
    
    -   **exit**: Encerra o shell.
    -   **echo [mensagem]**: Exibe a mensagem fornecida.
    -   **type [comando]**: Mostra se o comando é um comando interno do shell ou exibe o caminho do comando se encontrado no `PATH`.
    -   **pwd**: Exibe o diretório de trabalho atual.
    -   **cd [diretório]**: Altera o diretório de trabalho para o especificado.

## Estrutura do Código

-   **Função `isExecutable`**: Verifica se um arquivo é executável.
-   **Função `findInPath`**: Procura um comando nos diretórios especificados na variável de ambiente `PATH`.
-   **Função `changeDirectory`**: Altera o diretório de trabalho.
-   **Função `main`**: Contém o loop principal e processa os comandos do usuário.

## Exemplo de Uso

Ao iniciar o shell, você verá um prompt `$`. Você pode digitar os comandos suportados:

`$ pwd`
`/home/usuario`
`$ echo Hello, World!`
`Hello, World!`
`$ type echo`
`echo is a shell builtin`
`$ type ls`
`ls is /bin/ls`
`$ cd /home/usuario/Documents`
`$ pwd`
`/home/usuario/Documents`
`$ cd ..`
`$ pwd`
`/home/usuario`
`$ exit`
`Exiting shell...` `

## Notas

-   **Compatibilidade**: O shell atual é desenvolvido apenas para sistemas Unix. Não há suporte para Windows.