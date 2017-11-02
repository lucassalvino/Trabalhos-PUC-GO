using System;

namespace Automato
{
	class MainClass
	{
		public static void Main ()
		{
			try{
				AcoesAutomato run = new AcoesAutomato ();
				Console.WriteLine("Deseja verificar um DFA , NFA ou NFA-E (ARQ para ler de arquivo)(SAIR para finalizar):");
				string ler = Console.ReadLine();
				if(ler.Equals("DFA")){
					run.runDFA();
					throw new Exception("");
				}else{
					if(ler.Equals("NFA")){
						run.runNFA();
						throw new Exception("");
					}else{
						if(ler.Equals("NFA-E")){
							run.runNFAE();
						}else{
							if(ler.Equals("ARQ")){
								run.runArq();
							}else{
								if(ler.Equals("SAIR")){return;}
								throw new Exception("Valor ["+ler+"] é invalido.");;
							}
						}
					}
				}
			}
			catch(Exception erro){
				Console.WriteLine (erro.Message);
				Console.WriteLine ("Deseja Realizar mais alguma Operação(SIM/NAO): ");
				if (Console.ReadLine ().Equals ("SIM")) {
					Console.Clear ();
					Main ();
				}
			}
		}
	}
}
