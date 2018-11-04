#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(DISPLAY_ADDR, DISPLAY_COLS, DISPLAY_ROWS);

class Screen {
  private:
    String drinkname;
    byte multiplier = Store::multiplier;
    byte status = Store::status;
    
  public:
    void init() {
      lcd.init();
      lcd.backlight();
      this->render();
    }
    
    void checkDrinkName() {
      if(Store::selectedDrink.name != this->drinkname) {
        this->drinkname = Store::selectedDrink.name;
        this->render();
      }
    }

    void checkMultiplier() {
      if(Store::multiplier != this->multiplier) {
        this->multiplier = Store::multiplier;
        this->render();
      }
    }

    void checkStatus() {
      if(Store::status != this->status) {
        this->status = Store::status;
        this->render();
      }
    }
    
    void render() {
      lcd.clear();
      lcd.setCursor(0, 1);
      if(this->status == STATUS_READY) {
        lcd.print(this->drinkname);
      }
      else {
        lcd.print("Preparing...");
      }
      lcd.setCursor(14, 0);
      lcd.print("x");
      lcd.print(this->multiplier);
    }

    void loop() {
      this->checkStatus();
      this->checkMultiplier();
      this->checkDrinkName();
    }
};
