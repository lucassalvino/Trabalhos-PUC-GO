using System;
using System.IO;
//Exemplo de arquivo de entrada:
/*
DFA
A;B;C;D;E;F
A
D;E
0;1
A;B;0
A;C;1
B;D;1
C;E;0
E;E;1
D;D;0
B;F;0
C;F;1
D;F;1
E;F;0
F;F;0
F;F;1
*/
namespace Automato
{
	public class CarregaAutomatoArquivo
	{
		public static NFA_DFA carregaAutomato(string caminhoArquivo){
			if (!File.Exists (caminhoArquivo))
				throw new Exception ("O arquivo ["+caminhoArquivo+"] não existe.");
			Stream entrada = File.Open (caminhoArquivo,FileMode.Open);
			StreamReader arq = new StreamReader (entrada);
			string tipo = arq.ReadLine ();
			NFA_DFA ret= getTipoAutomato(tipo);
			lerStatus (ref ret, arq);//CARREGA OS ESTATOS DO AUTOMATO
			ret.setStatusInicial(arq.ReadLine());//le estado inicial
			lerStatusFinais(ref ret,arq);//carrega os estado finais
			lerAlfabeto(ref ret,arq);//carrefa as trnasicoes
			carregaTransicoes(ref ret,arq);//carrega transições
			arq.Close ();
			entrada.Close ();
			return ret;
		}

		private static NFA_DFA getTipoAutomato(string tipo){
			if(tipo=="NFA")return new NFA();
			if(tipo=="DFA")return new DFA();
			if (tipo == "NFA-E")return new NFA_E ();
			throw new Exception ("O tipo [" + tipo + "] não é válido");
		}

		private static void lerStatus(ref NFA_DFA au,StreamReader arq){
			string linha = arq.ReadLine ();
			string[] estados = linha.Split (';');
			foreach (string es in estados) {
				au.addStatus (es);
			}
		}
		private static void lerStatusFinais(ref NFA_DFA au,StreamReader arq){
			string linha = arq.ReadLine ();
			string[] estadosFinais = linha.Split (';');
			foreach (string esf in estadosFinais) {
				au.addStatusFinal (esf);
			}
		}
		private static void lerAlfabeto(ref NFA_DFA au,StreamReader arq){
			string linha = arq.ReadLine ();
			string[] transi = linha.Split (';');
			foreach (string tran in transi) {
				au.addSimbuloAlfabeto (tran.ToCharArray()[0]);
			}
		}
		private static void carregaTransicoes(ref NFA_DFA au, StreamReader arq){
			string linha;
			string[] transi;
			while ((linha = arq.ReadLine()) != null) {
				transi = linha.Split (';');
				au.addTransicao (transi[0],transi[2][0],transi[1]);
			}
		}
	}
}

