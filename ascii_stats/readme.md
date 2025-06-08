Analisador de Caracteres de Ficheiros
=====================================

Descrição:
-----------
Este programa analisa o conteúdo de um ficheiro de texto, contando e classificando os caracteres em diferentes categorias: dígitos, letras e outros caracteres. Fornece estatísticas detalhadas sobre a composição do ficheiro.

Funcionalidades:
----------------
- Análise de caracteres ASCII (letras e dígitos)
- Contagem de caracteres não-ASCII
- Suporte para múltiplas opções de linha de comando
- Tratamento de erros robusto com mensagens claras
- Sistema de ajuda integrado
- Verificação de versão
- Validação de ficheiros (existência, permissões, conteúdo)

Uso:
----
Sintaxe básica:
  ./analisador <opção> <nome_do_ficheiro>

Opções disponíveis:
  -f, --file     Analisar o ficheiro especificado
  -h, --help     Mostrar esta ajuda
  -V, --version  Mostrar versão do programa

Exemplo:
  ./analisador -f exemplo.txt

Saída típica:
O ficheiro 'exemplo.txt' tem:
    - '1024' bytes no total, dos quais:
        - '15' bytes não ASCII
        - '1009' bytes caracteres ASCII, dos quais:
            - '150' dígitos (0-9)
            - '800' letras (A-Z, a-z)
            - '59' outros caracteres ASCII

Requisitos:
-----------
- Sistema operativo: Qualquer sistema compatível com POSIX
- Compilador: GCC ou Clang (C99 ou superior)
- Bibliotecas: stdio.h, stdlib.h, unistd.h, fcntl.h, string.h, ctype.h

Limitações:
-----------
- Tamanho máximo do buffer: 1023 bytes
- Não processa ficheiros binários de forma otimizada
- Não suporta caracteres Unicode de múltiplos bytes

Autor:
-------
Duarte Lacerda

Versão:
--------
1.0

Licença:
---------
Licença MIT - livre para uso, modificação e distribuição.

---

Notas Adicionais:
1. O programa diferencia entre caracteres ASCII e não-ASCII
2. Caracteres especiais (espaços, pontuação, etc.) são contados como "outros"
3. O buffer de leitura tem tamanho fixo (1024 bytes)
4. Mensagens de erro são exibidas no stderr
5. O código de retorno 1 indica erros na execução