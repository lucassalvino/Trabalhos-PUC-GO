using System;
using System.Collections.Generic;

namespace Automato
{
	public class DFA : NFA_DFA
	{
		public DFA(){
			transicoes = new List<Transicao> ();
		}
		public override bool validaPalavra (string palavra){
			stadoAtual = statusInicial;//iniciando no status inicial
			foreach (char cont in palavra) {//valida cada caractere da palavra
				stadoAtual = getProxStatus(stadoAtual,cont);
				if (!status.Contains (stadoAtual)) {
					return false;
				}
			}
			if(statusFinais.Contains(stadoAtual))
				return true;
			return false;
		}
	}
}

