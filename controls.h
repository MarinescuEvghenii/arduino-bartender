class Controls {
  private:
    byte position = 0;
    byte previousState;
    byte presentState;

  public:
    Controls() {
      pinMode(ENCODER_CLK_PIN, INPUT);
      pinMode(ENCODER_DT_PIN, INPUT);
      pinMode(ENCODER_SW_PIN, INPUT);
      pinMode(STATUS_LED_PIN, OUTPUT);
      
      digitalWrite(ENCODER_SW_PIN, HIGH);
      
      this->previousState = digitalRead(ENCODER_CLK_PIN);
    }

    void updatePosition() {
      if(Store::status == STATUS_BUSY) {
        return;  
      }
      
      this->presentState = digitalRead(ENCODER_CLK_PIN);

      if (this->presentState != this->previousState) {     
        if (digitalRead(ENCODER_DT_PIN) != this->presentState) { 
          this->position++;
        } 
        else {
          this->position--;
        }
        this->previousState = this->presentState;
        Store::selectedDrink = Drinks::items[this->position % Drinks::size];
      }
    }

    void updateStartButtonStatus() {
      if(Store::status == STATUS_BUSY) {
        return;  
      }
      
      Store::startButtonPressed = !digitalRead(ENCODER_SW_PIN);  
    }

    void updateStatusLed() {
      digitalWrite(STATUS_LED_PIN, !Store::status);  
    }
    
    void loop() {   
      this->updatePosition();  
      this->updateStartButtonStatus();
      this->updateStatusLed();
   }
};
