using System;
using System.Collections.Generic;

namespace Automato
{
	public class NFA_DFA
	{
		public NFA_DFA (){
			alfabeto = new List<char> ();
			status = new List<string> ();
			statusFinais = new List<string> ();
			statusInicial ="";
		}

		public virtual bool validaPalavra (string palavra){
			return false;
		}

		public virtual void addTransicao(string stadoOriginal,char simbolo,string statoFinal){
			Transicao transi = new Transicao (stadoOriginal, simbolo, statoFinal);
			addTransicao (transi);
		}
		public virtual void removeTransicao(string stadoOriginal,char simbolo,string statoFinal){
			Transicao trans = new Transicao (stadoOriginal, simbolo, statoFinal);
			removeTransicao (trans);
		}

		public virtual void addTransicao(Transicao transi){
			if (!status.Contains (transi.EstadoAtual ()))
				throw new Exception ("O status ["+transi.EstadoAtual()+"] não existe no conjunto de estados.");
			if (!status.Contains (transi.EstadoFinal ()))
				throw new Exception ("O status ["+transi.EstadoFinal()+"] não existe no conjunto de estados.");
			if (!alfabeto.Contains (transi.SimboloAcao ()))
				throw new Exception ("O Simbolo [" + transi.SimboloAcao () + "] não existe no Alfabeto.");
			if (!transicoes.Contains (transi)) {
				transicoes.Add (transi);
			}
		}

		public virtual void removeTransicao (Transicao transi){
			if (transicoes.Contains (transi)) {
				transicoes.Remove (transi);
			}
		}



		public virtual string getProxStatus(string atual,char acao){
			string proxEstado = "";
			foreach (Transicao cont in transicoes) {
				if (cont.EstadoAtual () == atual && cont.SimboloAcao()==acao) {
					return cont.EstadoFinal();
				}
			}
			return proxEstado;
		}



		public bool validaTransicao(string stadoOriginal,char simbolo,string statoFinal){
			if (status.Contains (stadoOriginal) && status.Contains (statoFinal) && alfabeto.Contains (simbolo)) {
				return true;
			}
			return false;
		}

		public bool validaTransicao(Transicao transi){
			return validaTransicao (transi.EstadoAtual (), transi.SimboloAcao (), transi.EstadoFinal ());
		}
			
		public void addSimbuloAlfabeto(char simbulo){
			if(alfabeto.Contains(simbulo)){
				throw new Exception("Simbolo: ["+simbulo+"] já existe no Alfabeto");
			}
			alfabeto.Add(simbulo);
		}
		public void removeSombuloAlfabeto(char simbulo){
			if (alfabeto.Contains (simbulo)) {
				alfabeto.Remove (simbulo);
			}
		}
		public void addStatus(string statusAdd){
			if (status.Contains (statusAdd)) {
				throw new Exception("O Status: [" + statusAdd + "] já existe no conjunto de status.");
			}
			status.Add (statusAdd);
		}
		public void remoceStatus(string statusRemove){
			if (status.Contains (statusRemove)) {
				status.Remove (statusRemove);
			}
		}
		public void setStatusInicial(string statusIni){
			if (status.Contains (statusIni)) {
				statusInicial = statusIni;
			} else {
				throw new Exception("O status: ["+statusIni+"] não pertence ao conjunto de status.");
			}
		}
		public void addStatusFinal(string statusFinal){
			if (status.Contains (statusFinal)) {
				if (!statusFinais.Contains (statusFinal))//caso o status statusFinal não exista no conjunto statusFinais
					statusFinais.Add (statusFinal);
			} else {
				throw new Exception("O status ["+ statusFinal+"] Não pertence ao conjunto de status.");
			}
		}

		public string getStatusInicial(){return statusInicial;}
		public int getNumElementosAlfabeto(){return alfabeto.Count;}
		public int getNumStatus(){return status.Count;}
		public int getNumStatusFinal(){return statusFinais.Count;}

		protected List<char> alfabeto;
		protected List<string> status;
		protected string statusInicial;
		protected List<string> statusFinais;
		protected string stadoAtual;
		protected List<Transicao>transicoes;

		protected void clearNFA_DFA(){
			alfabeto.Clear ();
			status.Clear ();
			statusFinais.Clear ();
			statusInicial = "";
		}

	}
}

