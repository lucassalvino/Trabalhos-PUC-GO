using System;
using System.IO.MemoryMappedFiles;
	namespace Automato
	{
		public class AcoesAutomato
		{
			private int quantidadeStatus,quantidadeStatusFinais,itensAlfabeto,totalTrasi;
			private int i;
			NFA_DFA nfa_dfa;

			private void antesNumTransicao(){
				Console.WriteLine("Digite a quantidade de estados possíveis: ");
				quantidadeStatus = Convert.ToInt32( Console.ReadLine() );
				for(i=0;i<quantidadeStatus;i++){
					Console.Write("Digite o estado {0}: ",i+1);
					nfa_dfa.addStatus(Console.ReadLine());
				}

				Console.WriteLine("Digite o status Inicial: ");
				nfa_dfa.setStatusInicial(Console.ReadLine());

				Console.Write("Digite a quantidade de Estados Finais: ");
				quantidadeStatusFinais = Convert.ToInt32(Console.ReadLine());
				for(i =0;i<quantidadeStatusFinais;i++){
					Console.Write("Digite o estado Final {0}: ",i+1);
					nfa_dfa.addStatusFinal(Console.ReadLine());
				}

				Console.Write("Digite a quantidade de simbolos do alfabeto: ");
				itensAlfabeto = Convert.ToInt32(Console.ReadLine());
				for(i=0;i<itensAlfabeto;i++){
					Console.Write("Digite o Simbolo {0} do alfabeto: ", i+1);
					nfa_dfa.addSimbuloAlfabeto(Console.ReadLine()[0]);
				}

			}
			private void depoisTransicao(){
				for(i=0;i<totalTrasi;i++){
					string atual,destino;
					char acao;
					Console.Write("Digite o estado de origem {0}: ",i+1);
					atual = Console.ReadLine();
					Console.Write("Digite o estado de destino {0}: ",i+1);
					destino = Console.ReadLine();
					Console.Write("Digite o simbolo da transicao {0}: ",i+1);
					acao = Console.ReadLine()[0];
					nfa_dfa.addTransicao(atual,acao,destino);
				}
			}

			private void leValidaPalavra(){
				while(true){
					Console.WriteLine("Digite a palavra para validar (Parar digite (SAIR)): ");
					string palavra = Console.ReadLine();
					if(palavra.Equals("SAIR")){return;}
					if(nfa_dfa.validaPalavra(palavra)){
						Console.WriteLine("Palavra [{0}] Válida.",palavra);
					}else{
						Console.WriteLine("Palavra [{0}] Inválida.",palavra);
					}
				}
			}

			public void runDFA(){//DFA OK SEM MAIS PROBLEMAS
				nfa_dfa = new DFA();
				this.antesNumTransicao();

				totalTrasi = (quantidadeStatus*itensAlfabeto);
				Console.WriteLine("Será necessário digitar {0} transicoes: ",totalTrasi);

				this.depoisTransicao();
				leValidaPalavra();
			}

			public void runNFA(){
				nfa_dfa = new NFA();
				this.antesNumTransicao();

				Console.Write("Digite a quantidade de transições do NFA: ");
				totalTrasi = Convert.ToInt32(Console.ReadLine());
				if(totalTrasi<=0)throw new Exception("O automato deve possuir no mínimo uma transição.");

				this.depoisTransicao();
				leValidaPalavra();
			}

			public void runNFAE(){
				nfa_dfa = new NFA_E();
				this.antesNumTransicao();

				Console.Write("Digite a quantidade de transições do NFA-E: ");
				totalTrasi = Convert.ToInt32(Console.ReadLine());
				if(totalTrasi<=0)throw new Exception("O automato deve possuir no mínimo uma transição.");

				this.depoisTransicao();
				Console.WriteLine("Para Representar a Transição vazia digite o caractere | .");
				leValidaPalavra();
			}
			public void runArq(){
				Console.Write ("Digite o caminho do arquivo: ");
				string arq = Console.ReadLine(); 
				nfa_dfa = CarregaAutomatoArquivo.carregaAutomato (arq);
				leValidaPalavra ();
			}
		}
	}

