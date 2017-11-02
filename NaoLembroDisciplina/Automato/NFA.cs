using System;
using System.Collections.Generic;


namespace Automato
{
	public class NFA : NFA_DFA
	{
		public NFA (){transicoes = new List<Transicao> ();}
		public override bool validaPalavra (string palavra){
			List<string> statusAtual = new List<string>();
			statusAtual.Add (statusInicial);
			foreach (char at in palavra) {//analisar cada caractere aqui
				statusAtual = getProxEstados(statusAtual,at);
			}
			foreach (string estFin in statusAtual) {
				if (statusFinais.Contains (estFin))
					return true;
			}
			return false;
		}
		private List<string> getProxEstados (List<string> stAtual,char acao){
			List<string> ret = new List<string> ();
			foreach(string stadoList in stAtual){//para cada estado da Lista de estados atuais
				foreach (Transicao cont in transicoes) {
					if (cont.EstadoAtual () == stadoList && (cont.SimboloAcao()==acao)) {
						ret.Add(cont.EstadoFinal());//procurar a transicao para cada estado da lista
					}
				}
			}
			return ret;
		}
	}
}

