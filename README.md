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
   
## Imagens

Aqui estão algumas imagens do módulo em execução:

<p align="center">
  <img src="https://github.com/KrodrigoDev/Star-Wars-Kernel-Module/blob/main/Em%20execu%C3%A7%C3%A3o/Modulo%20em%20execu%C3%A7%C3%A3o%201%20(2).png?raw=true" alt="Imagem 1" width="500px">
</p>

<p align="center">
  <img src="https://github.com/KrodrigoDev/Star-Wars-Kernel-Module/blob/main/Em%20execu%C3%A7%C3%A3o/Modulo%20em%20execu%C3%A7%C3%A3o%201%20(1).png?raw=true" alt="Imagem 2" width="500px">
</p>

## Licença

Este módulo é licenciado sob a Licença GNU General Public License v3.0.

## Autor

Este módulo foi desenvolvido por Kauã Rodrigo de Lima Barbosa em sala de aula, com a ajuda do professor. [Aqui](https://github.com/quindai) está o perfil do professor no GitHub.
