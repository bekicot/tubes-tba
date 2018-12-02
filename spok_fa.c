#include "stdio.h"
#include "string.h"
#include "./spok_fa.h"
#include "stdbool.h"

bool parser(char* input);
struct StateMap {
  char input;
  const struct State *state;
};

struct State {
  struct StateMap nextStates[5];
  bool is_final;
};

const struct State Q0 = {
  .nextStates = {
    { .input='S', .state=&Q1 },
    { .input='K', .state=&Q5 },
    { .input='Y', .state=&Q10 }
  }
};

const struct State Q = {
  .nextStates = {
    { .input='S', .state=&Q1 },
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
  .nextStates = {
    { .input=' ', .state=&Q15 },
  }
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
  .nextStates = {
    { .input=' ', .state=&Q15 }
  }
};
const struct State Q9  = {
  .nextStates = {
    { .input=' ', .state=&Q15 }
  }
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
  .nextStates = {
    { .input=' ', .state=&Q15 }
  }
};
const struct State Q14  = {
  .nextStates = {
    { .input=' ', .state=&Q15 }
  }
};
const struct State Q15  = {
  .nextStates = {
    { .input='M', .state=&Q16 }
  }
  //.is_final = true
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
  .nextStates = {
    { .input=' ', .state=&Q31 }
  },
  .is_final = true
};
const struct State Q31  = {
  .nextStates = {
    { .input='A', .state=&Q32 },
    { .input='B', .state=&Q37 },
    { .input='D', .state=&Q41 }
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
    { .input='I', .state=&Q40 }
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
  .nextStates = {
    { .input=' ', .state=&Q60 }
  },
  .is_final = true
};

const struct State Q41  = {
  .nextStates = {
    { .input='I', .state=&Q42 }
  }
};
const struct State Q42  = {
  .nextStates = {
    { .input=' ', .state=&Q43 }
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
const struct State Q60  = {
  .nextStates = {
    { .input='D', .state=&Q41 }
  }
};


int main(int argc, char const *argv[])
{
  char input[100];
  printf("INPUT KALIMAT : ");
  scanf("%[^\n]%*c",input);
  printf("%i\n", parser(input));
  // printf("%i\n", parser("SAYA MENCURI BAJA DI RUMPUT"));
  return 0;
}

bool parser(char* input) {
  size_t inputLength = strlen(input);
  struct State currentState = Q0;
  for (int i = 0; i < inputLength; ++i)
  {
    size_t j = 0;
    bool valid = false;
    while(currentState.nextStates !=NULL && currentState.nextStates[j].state != NULL) {
      printf("%c\n", currentState.nextStates[j].input);
      if (input[i] == currentState.nextStates[j].input)
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
