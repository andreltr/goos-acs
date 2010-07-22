package alma.ucn.oca.ccd.utils;

public class gCCDNCEvent {

	private String type;
	private long id;
	private long total;
	
	public gCCDNCEvent(){
		
	}
	
	public gCCDNCEvent(String _type, long _id, long _total){
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
