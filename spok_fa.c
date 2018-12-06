#include "stdio.h"
#include "string.h"
#include <ctype.h>
#include "stdbool.h"
#include "./spok_fa.h"

bool faSubject(char* input);
bool faPredicate(char* input);
bool faObject(char* input);
bool faKeterangan(char* input);
bool fa(char* input, struct State initialState);
bool pdaSPOK(char* stacks);
void pop(char* stacks);
void push(char* stacks, char topChar);
void pdaGagal(char* grammar);
bool pda(char* grammar);

struct StateMap {
  char input;
  const struct State *state;
};

struct State {
  struct StateMap nextStates[5];
  bool is_final;
};

const struct State SUBJECT = {
  .nextStates = {
    { .input='S', .state=&Q1 },
    { .input='K', .state=&Q5 },
    { .input='Y', .state=&Q10 }
  }
};


const struct State Q1 = {
  .nextStates = {
    { .input='A', .state=&Q2 }
  }
};
const struct State Q2 = {
  .nextStates = {
    { .input='Y', .state=&Q3 }
  }
};
const struct State Q3  = {
  .nextStates = {
    { .input='A', .state=&Q4 }
  },
};
const struct State Q4  = {
  .is_final=true
};
const struct State Q5  = {
  .nextStates = {
    { .input='A', .state=&Q6 }
  }
};
const struct State Q6  = {
  .nextStates = {
    { .input='M', .state=&Q7 }
  }
};
const struct State Q7  = {
  .nextStates = {
    { .input='U', .state=&Q8 },
    { .input='I', .state=&Q9 }
  }
};
const struct State Q8  = {
  .is_final=true
};
const struct State Q9  = {
  .is_final=true
};
const struct State Q10  = {
  .nextStates = {
    { .input='A', .state=&Q11 }
  }
};
const struct State Q11  = {
  .nextStates = {
    { .input='N', .state=&Q12 }
  }
};
const struct State Q12  = {
  .nextStates = {
    { .input='A', .state=&Q13 },
    { .input='I', .state=&Q14 }
  }
};
const struct State Q13  = {
  .is_final=true
};
const struct State Q14  = {
  .is_final=true
};

// Predikat
const struct State PREDICATE  = {
  .nextStates = {
    { .input='M', .state=&Q16 }
  }
};
const struct State Q16  = {
  .nextStates = {
    { .input='E', .state=&Q17 },
    { .input='A', .state=&Q25 }
  }
};
const struct State Q17  = {
  .nextStates = {
    { .input='N', .state=&Q18 }
  }
};
const struct State Q18  = {
  .nextStates = {
    { .input='C', .state=&Q19 }
  }
};
const struct State Q19  = {
  .nextStates = {
    { .input='U', .state=&Q20 },
    { .input='A', .state=&Q23 }
  }
};
const struct State Q20  = {
  .nextStates = {
    { .input='C', .state=&Q21 },
    { .input='R', .state=&Q22 }
  }
};
const struct State Q21  = {
  .nextStates = {
    { .input='I', .state=&Q30 }
  }
};
const struct State Q22  = {
  .nextStates = {
    { .input='I', .state=&Q30 }
  }
};
const struct State Q23  = {
  .nextStates = {
    { .input='R', .state=&Q24 }
  }
};
const struct State Q24  = {
  .nextStates = {
    { .input='I', .state=&Q30 }
  }
};
const struct State Q25  = {
  .nextStates = {
    { .input='K', .state=&Q26 },
    { .input='N', .state=&Q28 }
  }
};
const struct State Q26  = {
  .nextStates = {
    { .input='A', .state=&Q27 }
  }
};
const struct State Q27  = {
  .nextStates = {
    { .input='N', .state=&Q30 }
  }
};
const struct State Q28  = {
  .nextStates = {
    { .input='D', .state=&Q29 }
  }
};
const struct State Q29  = {
  .nextStates = {
    { .input='I', .state=&Q30 }
  }
};
const struct State Q30  = {
  .is_final = true
};

// OBJECT
const struct State OBJECT  = {
  .nextStates = {
    { .input='A', .state=&Q32 },
    { .input='B', .state=&Q37 },
  }
};
const struct State Q32  = {
  .nextStates = {
    { .input='I', .state=&Q33 },
    { .input='K', .state=&Q34 },
    { .input='P', .state=&Q35 }
  }
};
const struct State Q33  = {
  .nextStates = {
    { .input='R', .state=&Q40 }
  }
};
const struct State Q34  = {
  .nextStates = {
    { .input='I', .state=&Q40 }
  }
};
const struct State Q35  = {
  .nextStates = {
    { .input='E', .state=&Q36 }
  }
};
const struct State Q36  = {
  .nextStates = {
    { .input='L', .state=&Q40 }
  }
};
const struct State Q37  = {
  .nextStates = {
    { .input='A', .state=&Q38 }
  }
};
const struct State Q38  = {
  .nextStates = {
    { .input='J', .state=&Q39 }
  }
};
const struct State Q39  = {
  .nextStates = {
    { .input='U', .state=&Q40 },
    { .input='A', .state=&Q40 }
  }
};
const struct State Q40  = {
  .is_final = true
};

const struct State Q41  = {
  .nextStates = {
    { .input='I', .state=&Q43 }
  }
};

const struct State Q43  = {
  .nextStates = {
    { .input='K', .state=&Q44 },
    { .input='R', .state=&Q46 },
    { .input='P', .state=&Q52 },
    { .input='M', .state=&Q56 }
  }
};
const struct State Q44  = {
  .nextStates = {
    { .input='O', .state=&Q45 }
  }
};
const struct State Q45  = {
  .nextStates = {
    { .input='S', .state=&Q59 }
  }
};
const struct State Q46  = {
  .nextStates = {
    { .input='U', .state=&Q47 }
  }
};
const struct State Q47  = {
  .nextStates = {
    { .input='M', .state=&Q48 }
  }
};
const struct State Q48  = {
  .nextStates = {
    { .input='A', .state=&Q49 },
    { .input='P', .state=&Q50 }
  }
};
const struct State Q49  = {
  .nextStates = {
    { .input='H', .state=&Q59 }
  }
};
const struct State Q50  = {
  .nextStates = {
    { .input='U', .state=&Q51 }
  }
};
const struct State Q51  = {
  .nextStates = {
    { .input='T', .state=&Q59 }
  }
};
const struct State Q52  = {
  .nextStates = {
    { .input='A', .state=&Q53 }
  }
};
const struct State Q53  = {
  .nextStates = {
    { .input='S', .state=&Q54 }
  }
};
const struct State Q54  = {
  .nextStates = {
    { .input='A', .state=&Q55 }
  }
};
const struct State Q55  = {
  .nextStates = {
    { .input='R', .state=&Q59 }
  }
};
const struct State Q56  = {
  .nextStates = {
    { .input='E', .state=&Q57 }
  }
};
const struct State Q57  = {
  .nextStates = {
    { .input='J', .state=&Q58 }
  }
};
const struct State Q58  = {
  .nextStates = {
    { .input='A', .state=&Q59 }
  }
};
const struct State Q59  = {
  .is_final = true
};

// KETERANGAN
const struct State KETERANGAN  = {
  .nextStates = {
    { .input='D', .state=&Q41 }
  }
};

bool fa(char* input, struct State initialState) {
  size_t inputLength = strlen(input);
  struct State currentState = initialState;
  for (int i = 0; i < inputLength; ++i)
  {
    size_t j = 0;
    bool valid = false;
    while(currentState.nextStates[j].state != NULL) {
      if (toupper((unsigned char) input[i]) == currentState.nextStates[j].input)
      {
        valid = true;
        currentState = *currentState.nextStates[j].state;
        break;
      }
      j++;
    }
    if(!valid) {
      return false;
    }
  }
  if(currentState.is_final)
    return true;
  return false;
}

bool faSubject(char* input) {
  return fa(input, SUBJECT);
}

bool faPredicate(char* input) {
  return fa(input, PREDICATE);
}

bool faObject(char* input) {
  return fa(input, OBJECT);
}

bool faKeterangan(char* input) {
  return fa(input, KETERANGAN);
}

bool pdaSPOK(char* stacks) {
  // int i;
  // while(true) {

  // }
  return 0;
}

void pop(char* stacks) {
  stacks[strlen(stacks) - 1] = 0;
}

void push(char* stacks, char topChar) {
  stacks[strlen(stacks)] =  topChar;
}

void pdaGagal(char* grammar) {
  printf("Grammar (%s) salah!", grammar);
}

bool pda(char* grammar) {
  char grammarCpy[100];
  strcpy(grammarCpy, grammar);

  char last = grammarCpy[strlen(grammarCpy) - 1];

  if(last == 'K') {
    pop(grammarCpy);
    last = grammarCpy[strlen(grammarCpy) - 1];
    if(*grammarCpy != 0 && last == 'P') {
      pop(grammarCpy);
      last = grammarCpy[strlen(grammarCpy) - 1];
      if(last == 'S') {
        pop(grammarCpy);
        if(*grammarCpy == 0)
          return true;
      }
    } else if (last == 'O') {
      pop(grammarCpy);
      last = grammarCpy[strlen(grammarCpy) - 1];
      if(*grammarCpy != 0 && last == 'P') {
        pop(grammarCpy);
        last = grammarCpy[strlen(grammarCpy) - 1];
        if(last == 'S') {
          pop(grammarCpy);
          if(*grammarCpy == 0)
            return true;
        }
      }
    }
  } else if(last == 'P') {
    pop(grammarCpy);
    last = grammarCpy[strlen(grammarCpy) - 1];
    if(last == 'S') {
      pop(grammarCpy);
      if(*grammarCpy == 0)
        return true;
    }
  } else if(last == 'O') {
    pop(grammarCpy);
    last = grammarCpy[strlen(grammarCpy) - 1];
    if(*grammarCpy != 0 && last == 'P') {
      pop(grammarCpy);
      last = grammarCpy[strlen(grammarCpy) - 1];
      if(last == 'S') {
        pop(grammarCpy);
        if(*grammarCpy == 0)
          return true;
      }
    }
  }
  return false;
}

void printValidKata() {
  printf("LIST KATA-KATA YANG DAPAT DIGUNAKAN\n\n");
  printf("SUBJEK : {KAMI,KAMU,YANA,YANI,SAYA}\n");
  printf("PREDIKAT : {MENCARI, MENCUCI, MENCURI, MAKAN, MANDI}\n");
  printf("OBJEK : {AIR, AKI, BAJU, BAJA, APEL}\n");
  printf("KETERANGAN : {DIRUMAH, DIRUMPUT, DIMEJA, DIPASAR, DIKOS}\n");
}

int main(int argc, char const *argv[])
{

  char input[100];
  input[99] = '\0';
  char grammar[100];

  printValidKata();
  printf("INPUT KALIMAT : ");
  scanf("%[^\n]%*c", input);

  char temp[100];
  strcpy(temp, input);

  char * kata = strtok (temp, " ,.-");
  while (kata != NULL)
  {
    if(faSubject(kata)) {
      push(grammar, 'S');
    } else if(faPredicate(kata)) {
      push(grammar, 'P');
    } else if(faObject(kata)) {
      push(grammar, 'O');
    } else if(faKeterangan(kata)) {
      push(grammar, 'K');
    } else {
      printf("Kata Tidak Valid (%s). Tidak melanjutkan proses ke pda\n", kata);
      return 1;
    }
    kata = strtok (NULL, " ,.-");
  }

  printf("Struktur kalimat terdeteksi sebagai (%s)\n", grammar);

  if(pda(grammar)) {
    printf("Kalimat \"%s\" valid.\n", input);
  } else {
    printf("Kalimat \"%s\" tidak valid\n", input);
  }

  return 0;
}
