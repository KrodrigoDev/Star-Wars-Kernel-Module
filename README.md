# Star Wars Kernel Module

Este é um módulo do kernel Linux que implementa uma funcionalidade simples com tema Star Wars. Ele cria um arquivo `/proc` chamado "K_RODRIGO_DEV" que exibe uma sequência de números.

## Como usar

1. Certifique-se de ter as dependências necessárias instaladas:
   - Linux Kernel (versão 5.6.0 ou superior)
   - Arquivos de cabeçalho do Kernel

2. Compile o módulo:
   ```shell
   make
   ```

3. Carregue o módulo no kernel:
   ```shell
   sudo insmod modulo.ko
   ```

4. Verifique a saída no arquivo `/proc/K_RODRIGO_DEV`:
   ```shell
   cat /proc/K_RODRIGO_DEV
   ```

5. Para remover o módulo do kernel, execute:
   ```shell
   sudo rmmod modulo
   ```

## Licença

Este módulo é licenciado sob a Licença Pública Geral GNU (GPL).

## Autor

Este módulo foi desenvolvido por Kauã Rodrigo de Lima Barbosa em sala de aula, com a ajuda do professor. [Aqui](https://github.com/quindai) está o perfil do professor no GitHub.

## Descrição

O módulo do kernel Linux "K_RODRIGO_DEV" é um pequeno exemplo que implementa um arquivo `/proc` personalizado. Ele exibe uma sequência de números incrementais quando o arquivo é lido. O módulo foi desenvolvido com o tema Star Wars e serve como uma demonstração simples do uso de arquivos `/proc` no kernel Linux.

Que a Força esteja com você, jovem programador!
