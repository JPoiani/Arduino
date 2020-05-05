// Pin mappings 
int segA = 2;
int segB = 6;
int segC = 4;
int segD = 3;
int segE = 0;
int segF = 1;
int segG = 5;
int segBigB = 12;
int segBigC = 13;
int dealer1 = 7;
int dealer2 = 8;
int dealer4 = 9;
int dealer8 = 10;
int dealer16 = 11;
int hitButton = A5;
int foldButton = A4;

// Pre-declaring function prototypes because the IDE gets confused somtimes 
void initialize();
void losingHand(int playerHand, int dealerHand);
void winningHand(int playerHand, int dealerHand);
void lightDealerHand(int number);
void lightNum(int number);

// Game values
int playerHand = 0;
int dealerHand = 0;
boolean dealersTurn = false;

void setup() {
  // put your setup code here, to run once:
  
  randomSeed(analogRead(A0));

  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segBigB, OUTPUT);
  pinMode(segBigC, OUTPUT);
  pinMode(dealer1, OUTPUT);
  pinMode(dealer2, OUTPUT);
  pinMode(dealer4, OUTPUT);
  pinMode(dealer8, OUTPUT);
  pinMode(dealer16, OUTPUT);
  initialize();
  delay(1000);
  lightNum(playerHand);
}

void loop() {
  
  if (analogRead(hitButton) > 512 && !dealersTurn) {
    
    playerHand = playerHand + random(9) + 1;
    
    if (playerHand > 19) {
      dealersTurn = true;
    } else if (playerHand < 19) {
      lightNum(playerHand);
    } else {
      winningHand();
    }
  }
  
  if (analogRead(foldButton) > 512) {
    dealersTurn = true;
  }
  
  while (dealersTurn) {
    
    if (playerHand > 19) {
      dealersTurn = false;
      losingHand();
    }

    if (dealerHand > 19) {
      dealersTurn = false;
      winningHand();
    }
    
    if (dealerHand < 14) {
      dealerHand = dealerHand + random(9) + 1;
    } else {
      if (dealerHand > playerHand) {
        dealersTurn = false;
        losingHand();
      } else {
        dealersTurn = false;
        winningHand();
      }
      
    }
    
    }
    delay(200);
}

void initialize() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segBigB, LOW);
  digitalWrite(segBigC, LOW);
  digitalWrite(dealer1, HIGH);
  digitalWrite(dealer2, HIGH);
  digitalWrite(dealer4, HIGH);
  digitalWrite(dealer8, HIGH);
  digitalWrite(dealer16, HIGH);
}

void losingHand() {

  // flash the dealers display, then their value
  for (int i = 0; i < 5; i++) {
    lightDealerHand(0);
    delay(1000);
    lightDealerHand(31);
    delay(1000);
  }
  lightDealerHand(dealerHand);
  delay(5000);
  playerHand = 0;
  dealerHand = 0;
  lightNum(0);
}

void winningHand() {

  delay(50);
  lightDealerHand(0);
  
  // flash the players display, then their value
  for (int i = 0; i < 5; i++) {
    initialize();
    delay(1000);
    lightNum(playerHand);
    
    delay(1000);
  }
  lightDealerHand(dealerHand);
  delay(5000);
  playerHand = 0;
  dealerHand = 0;
  lightNum(playerHand);
}

void lightDealerHand(int number) {
  
  if (bitRead(number, 0) == 1) {
    digitalWrite(dealer1, LOW);
  } else {
    digitalWrite(dealer1, HIGH);
  }
  if (bitRead(number, 1) == 1) {
    digitalWrite(dealer2, LOW);
  } else {
    digitalWrite(dealer2, HIGH);
  }
  if (bitRead(number, 2) == 1) {
    digitalWrite(dealer4, LOW);
  } else {
    digitalWrite(dealer4, HIGH);
  }
  if (bitRead(number, 3) == 1) {
    digitalWrite(dealer8, LOW);
  } else {
    digitalWrite(dealer8, HIGH);
  }
  if (bitRead(number, 4) == 1) {
    digitalWrite(dealer16, LOW);
  } else {
    digitalWrite(dealer16, HIGH);
  }
}

void lightNum(int number) {
  /*
   * Seeing as these are base 10 numbers, I'll do case statements
   * instead of the logic for individual segments
   */
   boolean over9 = false;
   if (number > 9) {
    number = number - 10;
    over9 = true;
   }
   switch (number) {
    case 0:
      //
      initialize();
      delay(100);
      digitalWrite(segA, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segB, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
    case 1:
      //
      initialize();
      delay(100);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
    case 2:
      //
      initialize();
      delay(100);
      digitalWrite(segA, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segG, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segD, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
    case 3:
      //
      initialize();
      delay(100);
      digitalWrite(segA, LOW);
      digitalWrite(segG, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segB, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
    case 4:
      //
      initialize();
      delay(100);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segB, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
    case 5:
      //
      initialize();
      delay(100);
      digitalWrite(segA, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segC, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
    case 6:
      //
      initialize();
      delay(100);
      digitalWrite(segA, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segG, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
    case 7:
      //
      initialize();
      delay(100);
      digitalWrite(segA, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segC, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
    case 8:
      //
      initialize();
      delay(100);
      digitalWrite(segA, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segB, LOW);
      digitalWrite(segG, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
    case 9:
      //
      initialize();
      delay(100);
      digitalWrite(segA, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segB, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
    default:
      //
      initialize();
      delay(100);
      digitalWrite(segA, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segD, LOW);
      digitalWrite(segC, LOW);
      digitalWrite(segB, LOW);
      if (over9) {
        digitalWrite(segBigB, HIGH);
        digitalWrite(segBigC, HIGH);
      }
      break;
   }
}
