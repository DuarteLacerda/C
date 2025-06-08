Processador de Ficheiros com Substituição de Espaços
===================================================

Descrição:
-----------
Este programa lê um ficheiro de texto especificado pelo utilizador, substitui todos os espaços por underscores (_) e grava apenas as linhas modificadas num novo ficheiro com extensão .out. O programa mostra o conteúdo modificado no terminal e relata o número de linhas alteradas.

Funcionalidades:
----------------
- Processamento de ficheiros de texto com validação de entrada
- Substituição automática de espaços por underscores
- Filtragem para gravar apenas linhas modificadas
- Geração automática do nome do ficheiro de saída (adiciona .out)
- Relatório de linhas modificadas
- Mensagens de erro detalhadas para problemas de I/O
- Gestão segura de descritores de ficheiros

Uso:
----
Execute o programa com o seguinte comando:

  ./programa --file nome_do_ficheiro.txt

O programa criará um novo ficheiro chamado nome_do_ficheiro.txt.out contendo apenas as linhas que foram modificadas.

Requisitos:
-----------
- Sistema operativo POSIX (Linux, macOS, etc.)
- Compilador C compatível com C99
- Bibliotecas: stdio.h, stdlib.h, unistd.h, fcntl.h, string.h

Limitações:
-----------
- Tamanho máximo do buffer: 1023 bytes
- Não processa ficheiros com linhas muito longas (>1023 caracteres)
- Apenas substitui espaços simples (não trata de tabs ou múltiplos espaços)
- O nome do ficheiro de saída não pode exceder 1023 caracteres

Autor:
-------
Duarte Lacerda

Versão:
--------
1.0

Licença:
---------
Licença MIT - livre para uso e modificação.

---

Notas:
1. O programa preserva a formatação original exceto pela substituição de espaços
2. Linhas sem espaços não são incluídas no ficheiro de saída
3. Em caso de erro, o programa retorna código 1 com mensagem descritiva
4. O ficheiro original nunca é alterado, apenas é criado um novo ficheiro

Exemplo de saída no terminal:
Modified content:
Texto_com_espacos_substituidos
Outra_linha_modificada