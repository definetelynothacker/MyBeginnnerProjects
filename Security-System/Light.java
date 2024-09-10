public class Light{
    
    public String ID;
    public boolean isOn;
    public Location location;
    
    public void turnOn(){
        this.isOn = true;
    }
    public void turnOff(){
        this.isOn = false;
    }
    public boolean isLightOn(){
        if(this.isOn)
            return true;
        return false;
    }
}