import java.util.ArrayList;

public class Mensagem {
	public static enum TipoMensagem{
		Requisicao, Resposta;
	}
	
	private TipoMensagem tipoMensagem;
	private int idRequisicao;
	private int idMetodo;
	private ArrayList<String> argumentos;
	private ReferenciaObjetoRemoto referenciaObjeto;
	private String textoMensagem;
	
	public String getTextoMensagem() {
		return textoMensagem;
	}
	public void setTextoMensagem(String textoMensagem) {
		this.textoMensagem = textoMensagem;
	}
	public TipoMensagem getTipoMensagem() {
		return tipoMensagem;
	}
	public void setTipoMensagem(TipoMensagem tipoMensagem) {
		this.tipoMensagem = tipoMensagem;
	}
	public int getIdRequisicao() {
		return idRequisicao;
	}
	public void setIdRequisicao(int idRequisicao) {
		this.idRequisicao = idRequisicao;
	}
	public int getIdMetodo() {
		return idMetodo;
	}
	public void setIdMetodo(int idMetodo) {
		this.idMetodo = idMetodo;
	}
	public ArrayList<String> getArgumentos() {
		return argumentos;
	}
	public void setArgumentos(ArrayList<String> argumentos) {
		this.argumentos = argumentos;
	}
	public ReferenciaObjetoRemoto getReferenciaObjeto() {
		return referenciaObjeto;
	}
	public void setReferenciaObjeto(ReferenciaObjetoRemoto referenciaObjeto) {
		this.referenciaObjeto = referenciaObjeto;
	}
	
	
	
}
