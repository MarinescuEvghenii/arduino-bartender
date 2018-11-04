namespace Drinks {  
  const byte size = 8;

  struct Drink {
    String name;
    byte ingredients[PUMP_COUNT];
    float quantity[PUMP_COUNT];
  };
  
  Drink RumCoke = {
    "Rum & Coke",
    {RUM, COKE},
    {50,  150}
  };
  
  Drink WhiskeyCoke = {
    "Whiskey & Coke",
    {WHISKEY, COKE},
    {50,      150}
  };
  
  Drink JinTonic = {
    "Gin & Tonic",
    {GIN, TONIC},
    {50,  150}
  };
  
  Drink JinJuice = {
    "Gin & Juice",
    {GIN, ORANGE_JUICE},
    {50,  150}
  };
  
  Drink Screwdriver = {
    "Screwdriver",
    {VODCA, ORANGE_JUICE},
    {50,    150}
  };
  
  Drink TequilaSunrise = {
    "Tequila Sunrise",
    {TEQUILA, ORANGE_JUICE},
    {50,      150}
  };
  
  Drink LongIsland = {
    "Long Island",
    {GIN, RUM, VODCA, TEQUILA, COKE, ORANGE_JUICE},
    {15,  15,  15,    15,      100,  30}
  };
  
  Drink Margarita = {
    "Margarita",
    {TEQUILA, MARGARITA_MIX},
    {50,      150}
  };

  Drink items[size] = {
      RumCoke,
      WhiskeyCoke,
      JinTonic, 
      Screwdriver,
      TequilaSunrise,
      JinJuice,
      LongIsland,
      Margarita
  };
}
