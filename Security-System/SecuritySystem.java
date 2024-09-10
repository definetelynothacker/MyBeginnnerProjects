import java.util.List;
import java.util.Iterator;

public class SecuritySystem{
    public List<Light> lights;
    public List<ThreatDetector> detectors;
    Iterator<Light> it = lights.iterator();
    
    
    public void turnOnAllLights(){
        for(Light light: lights){
            if(!light.isOn)
                light.turnOn();
        }
    }
    public void turnOffAllLights(){
        for(Light light: lights){
            if(light.isOn)
                light.turnOff();
        }
    }
    public void turnOnSpecificLights(List<Light> specificLights){
        for(Light light: specificLights){
            if(!light.isOn)
                light.turnOn();
        }
    }
    public void turnOffSpecificLights(List<Light> specificLights){
        for(Light light: specificLights){
            if(light.isOn)
                light.turnOn();
        }
    }
    void detectThreat(){
        for(ThreatDetector potentialThreats: detectors){
            if(potentialThreats.isActive)
                turnOnAllLights();
        }
    }
}