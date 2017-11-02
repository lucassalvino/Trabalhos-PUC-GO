using System;
using System.Collections.Generic;
// 5    295
namespace Automato
{
	public class NFA_E : NFA_DFA
	{
		public NFA_E (){
			transicoes = new 	List<Transicao> ();
			addSimbuloAlfabeto ('|');//adiciona | ao aufabeto. | é o E
		}

		public override bool validaPalavra (string palavra){
			List<string> statusAtual = new List<string>();
			statusAtual.Add (statusInicial);
			statusAtual = getStatusEpson (statusAtual,true);
			foreach (char at in palavra) {//analisar cada caractere aqui
				statusAtual = getProxEstados(statusAtual,at);
			}
			foreach (string estFin in statusAtual) {
				if (statusFinais.Contains (estFin))
					return true;
			}	
			return false;
		}

		private List<string> getStatusEpson(List<string> stAtual,bool copia){
			List<string> ret  = new List<string>();
			bool add=false;
			if (copia)
				foreach (string a in stAtual) {ret.Add (a);}//evitar erro idiota: Collection was modified; enumeration operation may not execute.
			foreach (string at in stAtual) {
				foreach (Transicao trans in transicoes) {
					if (trans.EstadoAtual () == at && trans.SimboloAcao()=='|') {
						if (!stAtual.Contains (trans.EstadoFinal ()) && !ret.Contains(trans.EstadoFinal())) {
							ret.Add (trans.EstadoFinal());
							add = true;
						}
					}
				}
			}
			if (add) {
				ret = getStatusEpson (ret,true);
			}
			return ret;
		}

		private List<string> getProxEstados (List<string> stAtual,char acao){
			List<string> ret = new List<string> ();
			ret = getStatusEpson (stAtual,false);
			foreach(string stadoList in stAtual){//para cada estado da Lista de estados atuais
				ret = getStatusEpson (ret,true);
				foreach (Transicao cont in transicoes) {
					if (cont.EstadoAtual () == stadoList && (cont.SimboloAcao()==acao||cont.SimboloAcao() == '|')) {
						if(!ret.Contains(cont.EstadoFinal())){
							ret.Add(cont.EstadoFinal());//adiciona o estado final à lista
						}
					}
				}
			}
			return getStatusEpson (ret,true);
		}
	}
}

