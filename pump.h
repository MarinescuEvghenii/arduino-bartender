class Pump {
  private:
    byte pin;
    byte ingredient;
    byte status = STATUS_READY;
    unsigned long offTime = 0;

  public:
    Pump(byte pin, byte ingredient) {
      this->pin = pin;
      this->ingredient = ingredient;
      pinMode(pin, OUTPUT);
    }

    void on(unsigned long offTime) {
      if(this->status == STATUS_READY) {
        this->offTime = millis() + offTime;
        this->status = STATUS_BUSY;
        digitalWrite(pin, HIGH);
      }
    }

    void off() {
      this->status = STATUS_READY;
      digitalWrite(pin, LOW);
    }

    byte getStatus() {
      return this->status;
    }

    byte getIngredient() {
      return this->ingredient;
    }
    
    void loop() {
      if (this->offTime != 0 && millis() > this->offTime) {
        this->offTime = 0;
        this->off();
      }
    }
};
