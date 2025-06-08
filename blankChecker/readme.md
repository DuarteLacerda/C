Contador e Conversor de Caracteres Especiais
============================================

Descrição:
-----------
Este programa analisa um ficheiro de texto, contando espaços, tabulações e quebras de linha. Além disso, converte o conteúdo substituindo:
- Espaços (' ') por underscores ('_')
- Tabulações ('\t') por hífens ('-')
- Quebras de linha ('\n') por espaços (' ')
O resultado é guardado no ficheiro 'output.txt'.

Funcionalidades:
----------------
- Contagem precisa de espaços, tabs e quebras de linha
- Conversão de caracteres especiais com substituição configurável
- Validação do tamanho do ficheiro (até 256 linhas de 1024 caracteres)
- Geração de ficheiro de saída com conteúdo convertido
- Tratamento robusto de erros com mensagens claras
- Gestão segura de recursos (abertura/fecho de ficheiros)

Uso:
----
Sintaxe:
  ./programa --file <nome_do_ficheiro>

Exemplo:
  ./conversor --file documento.txt

Saída típica:
Total de espaços: 120
Total de tabulações: 15
Total de quebras de linha: 30

Converted content saved to 'output.txt'.

Requisitos:
-----------
- Sistema operativo: Qualquer sistema compatível com POSIX
- Compilador: GCC ou Clang (C99 ou superior)
- Bibliotecas: stdio.h, stdlib.h, unistd.h, fcntl.h, string.h, ctype.h

Limitações:
-----------
- Tamanho máximo do ficheiro: 256 linhas × 1024 caracteres
- Buffer fixo de 1024 bytes por operação de leitura
- Não preserva formatação original no ficheiro de saída
- Substituições são permanentes no ficheiro de saída

Autor:
-------
Duarte Lacerda

Versão:
--------
1.0

Licença:
---------
Licença MIT - livre para uso e distribuição.

---

Notas Importantes:
1. O ficheiro original permanece inalterado
2. O ficheiro 'output.txt' é sempre sobrescrito se existir
3. Caracteres especiais não mencionados permanecem inalterados
4. Códigos de erro:
   - 0: Sucesso
   - 1: Erro na execução (detalhes no stderr)