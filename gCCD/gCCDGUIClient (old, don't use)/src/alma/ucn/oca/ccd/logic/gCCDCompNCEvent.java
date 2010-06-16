package alma.ucn.oca.ccd.logic;

public class gCCDCompNCEvent {

	private String type;
	private long id;
	private long total;
	
	public gCCDCompNCEvent(){
		
	}
	
	public gCCDCompNCEvent(String _type, long _id, long _total){
		type = _type;
		id = _id;
		total = _total;		
	}
	
	public String getType(){
		return this.type;
	}

	public long getID(){
		return this.id;
	}
	
	public long getTotal(){
		return this.total;
	}
}
