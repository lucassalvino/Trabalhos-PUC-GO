using System;

namespace Automato
{
	public class Transicao
	{
		public Transicao ()
		{
			estadoFinal = estadoAtual = "";
			simboloAcao = ' ';
		}
		public Transicao (string statusAtual,char acao,string statusFinal){
			EstadoAtual (statusAtual);
			EstadoFinal (statusFinal);
			SimboloAcao (acao);
		}
		private string estadoAtual;
		private string estadoFinal;
		private char simboloAcao;

		public string EstadoAtual(){return estadoAtual;}
		public string EstadoFinal(){return estadoFinal;}
		public char SimboloAcao(){return simboloAcao;}
		public void EstadoAtual(string staAtual){estadoAtual = staAtual;}
		public void EstadoFinal(string staFinal){estadoFinal = staFinal;}
		public void SimboloAcao(char acao){simboloAcao = acao;}
	}
}

