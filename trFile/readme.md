Conversor de Maiúsculas/Minúsculas para Arquivos de Texto
=======================================================

Descrição:
----------
Este programa lê um arquivo de texto e oferece opções para converter o conteúdo para maiúsculas ou minúsculas. O conteúdo convertido é exibido no console. Inclui tratamento robusto de erros para operações com arquivos e argumentos de linha de comando.

Funcionalidades:
---------------
- Lê arquivo de texto especificado via argumento de linha de comando
- Opção de conversão de caixa (maiúsculas ou minúsculas)
- Exibe o conteúdo do arquivo no console
- Tratamento abrangente de erros para:
  - Argumentos ausentes ou inválidos
  - Erros ao abrir/ler arquivos
  - Opções de conversão inválidas
  - Arquivos vazios
- Interface de linha de comando simples e intuitiva

Como Usar:
----------
Sintaxe básica:
  ./programa --filename <nome_arquivo> [--option L/l | U/u]

Opções:
  --filename    Especifica o arquivo de entrada (obrigatório)
  --option      Opção de conversão (opcional):
                L/l - Converter para minúsculas
                U/u - Converter para maiúsculas

Exemplos:
1. Exibir conteúdo sem conversão:
   ./conversor --filename exemplo.txt

2. Converter para maiúsculas e exibir:
   ./conversor --filename exemplo.txt --option U

3. Converter para minúsculas e exibir:
   ./conversor --filename exemplo.txt --option l

Requisitos:
-----------
- Sistema operacional compatível com POSIX
- Compilador C (C99 ou superior)
- Bibliotecas padrão:
  stdio.h, stdlib.h, unistd.h,
  fcntl.h, string.h, ctype.h

Limitações:
-----------
- Tamanho máximo do buffer: 1023 bytes
- Processa apenas caracteres ASCII
- Não salva o resultado convertido em arquivo
- Não suporta caracteres Unicode

Tratamento de Erros:
-------------------
- Argumento de nome de arquivo ausente
- Argumento de opção inválido
- Arquivo não encontrado
- Erros de leitura do arquivo
- Arquivo vazio
- Opção de conversão inválida

Autor:
------
Duarte Lacerda

Versão:
-------
1.0

Licença:
--------
Licença MIT - livre para uso e modificação

---

Observações:
1. O programa apenas exibe o texto convertido, não modifica o arquivo original
2. Sem a flag --option, o conteúdo é exibido sem alterações
3. Mensagens de erro são exibidas no stderr
4. Códigos de retorno:
   - 0: Sucesso
   - 1: Ocorreu um erro
5. A conversão de caixa aplica-se a todos os caracteres alfabéticos do arquivo