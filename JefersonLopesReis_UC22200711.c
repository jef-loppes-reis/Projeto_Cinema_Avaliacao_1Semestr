#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    // Cabecario//
    printf("\n\n############ Projeto Final V1.0 ############\n\n");// Nome do projeto;
    printf("          Nome Completo: Jeferson Lopes Reis\n");       // Nome do aluno;
    printf("          Matricula: UC22200711\n");                    // Codigo de matricula do aluno;
    printf("          Curso: Ciencia da Computacao\n\n");           // Nome do curso;

    // Definicoes das variaveis
    char sexoPessoa,// Variavel para receber o sexo da pessoa (M ou F);
        continuar,// Variavel para recber a opcao (S -Sim, N - Nao);
        nomeFilme1[30],// Variavel para receber o nome do primeiro filme;
        nomeFilme2[30];// Variavel para receber o nome do segundo filme;

    int qtdSessoes,// Varivel para definir a quantadade de sessoes;
        qtdPessoas,// Variavel para definir a quantidade de pessoas;
        qtdTotalSexoM = 0,// Variavel para definir a quantidade de pessoas do sexo masculino;
        qtdTotalSexoF = 0,// variavel para definiar a quantidade de pessoas do sexo feminino;
        idadePessoa,// Variavel para receber a idade da pessoa;
        opcaoEntrada,// Variavel para receber a opcao de entredada (Inteira ou Meia);
        qtdIngressoInteira,// Variavel para receber a quantidade total de ingressos (Inteira);
        qtdIngressoMeia,// Variavel para receber a quantidade total de ingressos (Meia);
        codFilme,// Variavel para receber o codigo do filme;
        qtdFilme1,// Variavel para receber a quantidade total de pessoas qua vao assitir o primeiro filme;
        qtdFilme2,// Variavel para receber a quantidade total de pessoas qua vao assitir o segundo filme;
        codClassificao1,// Variavel para definiar o codigo de classificacao (Criancas);
        codClassificao2,// Variavel para definiar o codigo de classificacao (Adolecentes);
        codClassificao3,// Variavel para definiar o codigo de classificacao (Adultos);
        codClassificao4;// Variavel para definiar o codigo de classificacao (Idosos);

    float qtdArrecadaSessao;// Variavel para receber a quantidade total de ingressos arrecadada por sessao;

    do
    {
        // 1. Solicite a quantidade de sessões, aceitando exatamente 2 (duas) sessões.//
        fflush(stdin);// Limpa o cache da memoria;
        printf("Digite 2 para definir as duas sessoes: \n");//Pede ao usuario a quantidade de sessoes;
        scanf("%d", &qtdSessoes);// Ler a quantidade de sessoes;

        fflush(stdin);// Limpa o cache da memoria;
        printf("Nome do filme para a primeira sessao: \n");// Pede ao usario o nome do primeiro filme;
        scanf("%s", &nomeFilme1);// Ler o nome do primeiro filme;

        fflush(stdin);// Limpa o cache da memoria;
        printf("Nome do filme para a segunda sessao: \n");// Pede ao usario o nome do segundo filme;
        scanf("%s", &nomeFilme2);// Ler o nome do segundo filme;

        // 2. Solicite a quantidade de pessoas que assistiram ao filme, não aceitando valor inferior a 10 (dez).//
        fflush(stdin);// Limpa o cache da memoria;
        printf("Digite a quantidade de Pessoas, minimo 10 (Dez)! : \n");// Pede ao usuario a quantidade de pessoas, no minino 10;
        scanf("%d", &qtdPessoas);// Ler a quantidade de pessoas;

        system("cls");// Limpa o console (CMD/Terminal);

    } while (qtdSessoes != 2 && qtdPessoas <= 10);// Condicao para o (Do While)

    printf("\n---------------------------------------------------\n");// Printf com tracos, somente para saparar o codigo;
    printf("Quantidade de (Sessoes): %d\n", qtdSessoes);// Imprime a quantidade de Sessoes;
    printf("Quantidade de (Pessoas): %d\n", qtdPessoas);// Imprime a quantidade de Pessoas;
    printf("\n---------------------------------------------------");// Printf com tracos, somente para saparar o codigo;

    fflush(stdin);// Limpa o cache da memoria;
    printf("\n\nContinuar ?: [S] Sim, [N] Nao.\n");// Pede a opcao ao usuario;
    scanf("%c", &continuar);// Ler a opcao;

    if (toupper(continuar) == 'S')// Condicao IF, para validade a opcao acima;
    {

        for (int i = 0; i < qtdPessoas; i++)// (For) para percorrer a quantidade de pessoas;
        {
            system("cls");// Limpa o console (CMD/Terminal);

            fflush(stdin);// Limpa o cache da memoria;
            printf("\n\nQual o nome do filme ingresso %d: \n1- %s\n2- %s\n[1] ou [2] ?: ", i, nomeFilme1, nomeFilme2);// Pede ao usario qual filme a pessoa vai assitir;
            scanf("%d", &codFilme);// Ler o codigo do filme;

            // 3. Para cada pessoa que assistiu ao filme deverá ser solicitado e validado o sexo (M -masculino, F - Feminino) e a idade (de 3 a 100 anos)
            fflush(stdin); // Funcao para limpar o Cache de Memoria.
            printf("\nDigite o (Sexo) M - Masculino ou F - Feminino, do ingresso numero %d: ", i);// Pede ao usuario o sexo da pessoa;
            scanf("%c", &sexoPessoa);// Ler o sexo;

            fflush(stdin); // Funcao para limpar o Cache de Memoria.
            printf("\nDigite a (Idade) de 3 a 100 anos, do ingresso numero %d: ", i);// Pede ao usuario a idade da pessoa;
            scanf("%d", &idadePessoa);// Ler a idade;

            // 4. Apresentar ao usuário apenas as opções Inteira e Meia (0,4 ponto), e somar o valor
            // arrecadado na sessão, considerando que a inteira custa R$50,00 e a meia R$25,00
            fflush(stdin);// Limpa o cache da memoria;
            printf("\nQual foi a opcao de entrada a sessao, ao ingresso numero %d?: \n1 - Inteira -> R$ 50,00;\n2 - Meia -> R$ 25,00;\n[1] ou [2]?: ", i);// Pede ao usario qual o tipo de ingresso (Inteira ou Meia);
            scanf("%d", &opcaoEntrada);// Ler a opcao;

            // Condicao selecao ao nome do filme.
            switch (codFilme)
            {
            case 1:
                qtdFilme1++;// Caso for codigo 1, conta mais 1;
                break;
            case 2:
                qtdFilme2++;// Caso for codigo 2, conta mais 1;
            default:
                break;
            }

            // Condicao selecao ao tipo do sexo.
            if (toupper(sexoPessoa) == 'M')// Caso for sexo Masculino M, conta mais 1. OBS: Utilizando a funcao "toupper()" para deixar o char sempre em letra maiuscula;
            { // Funcao para deixar o char sempre em letra maiuscula.
                qtdTotalSexoM++;
            }
            if (toupper(sexoPessoa) == 'F')// Caso for sexo Feminino F, conta mais 1. OBS: Utilizando a funcao "toupper()" para deixar o char sempre em letra maiuscula;
            { // Funcao para deixar o char sempre em letra maiuscula.
                qtdTotalSexoF++;
            }

            // Condicao para contar a quantidade de classificao.
            if (idadePessoa >= 3 && idadePessoa <= 13)// Caso idade da pessoa estiver entre 3 e 13 anos, define como (Crianca) e conta mais 1;
            {
                codClassificao1++;
            }
            else if (idadePessoa >= 14 && idadePessoa <= 17)// Caso idade da pessoa estiver entre 14 e 17 anos, define como (Adolecente) e conta mais 1;
            {
                codClassificao2++;
            }
            else if (idadePessoa >= 18 && idadePessoa <= 64)// Caso idade da pessoa estiver entre 18 e 64 anos, define como (Adulto) e conta mais 1;
            {
                codClassificao3++;
            }
            else if (idadePessoa >= 65 && idadePessoa <= 100)// Caso idade da pessoa estiver entre 65 e 100 anos, define como (Idoso) e conta mais 1;
            {
                codClassificao4++;
            }

            // Condicao selecao ao tipo do ingresso.
            if (opcaoEntrada == 1)// Caso a opcao do ingresso seja 1 = Inteira, conta mais 1
            {
                qtdIngressoInteira++;
            }
            else if (opcaoEntrada == 2)// Caso a opcao do ingresso seja 2 = Meia, conta mais 1
            {
                qtdIngressoMeia++;
            }
        }

        system("cls");

        fflush(stdin);
        printf("\n----------------------------------------------------------");

        // 5. o nome do filme, a quantidade de pessoas do sexo feminino e a quantidade de pessoas do sexo masculino que assistiram ao filme
        printf("\nQuantidade total de pessoas que foram para (Primeira Sessao) filme -> %s <-: %d", nomeFilme1, qtdFilme1);
        printf("\nQuantidade total de pessoas que foram para (Segunda Sessao) filme -> %s <-: %d", nomeFilme2, qtdFilme2);
        fflush(stdin);
        printf("\n\nQuantidade total do sexo M - Masculino: %d", qtdTotalSexoM);
        printf("\nQuantidade total do sexo F - Feminino: %d", qtdTotalSexoF);

        fflush(stdin);
        printf("\n----------------------------------------------------------");

        // 6. a quantidade de pessoas, seguindo a classificação por idade indicada abaixo.
        fflush(stdin);
        printf("\n\nQuantidade total de pessoas para Classificao (Criancas): %d", codClassificao1);
        printf("\nQuantidade total de pessoas para Classificao (Adolecentes): %d", codClassificao2);
        printf("\nQuantidade total de pessoas para Classificao (Adultos): %d", codClassificao3);
        printf("\nQuantidade total de pessoas para Classificao (Idosos): %d\n\n", codClassificao4);

        fflush(stdin);
        printf("\n----------------------------------------------------------");

        // 8. Informar o valor total arrecadado em cada sessão e informar se houve mais pagamento de inteira que de meia entrada.
        fflush(stdin);
        printf("\n\nQuantidade total de ingressos de entrada (Inteira): %d\nValor Total em R$: %.2f", qtdIngressoInteira, (50.00 * qtdIngressoInteira));
        printf("\n\nQuantidade total de ingressos de (Meia) entrada: %d\nValor Total em R$: %.2f", qtdIngressoMeia, (25.00 * qtdIngressoMeia));

        printf("\n\n############ Projeto Final V1.0 ############\n\n");
        printf("          Nome Completo: Jeferson Lopes Reis\n");
        printf("          Matricula: UC22200711\n");
        printf("          Curso: Ciencia da Computacao\n\n");
    }
    else
    {
        printf("Fim do Codigo !!");
    }
}