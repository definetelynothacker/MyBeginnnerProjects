public class ThreatDetector{
    public String ID;
    public boolean isActive;
    
    
    public boolean detectThreat(){
        if(!isActive){
            System.out.println("Threat detector Not active");
            return false;
        }
        return true;
    }
    
    public void setID(String ID){
        this.ID = ID;
    }
    public void activate(){
        this.isActive = true;
        System.out.println("Threat detector activated");
    }
    public void deactivate(){
        this.isActive = false;
        System.out.println("Threat detector de-activated");
    }
}