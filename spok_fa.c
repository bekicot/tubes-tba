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
    { .input=' ', .state=&Q5 }
  }
};
const struct State Q15  = {
  .nextStates = {
    { .input='M', .state=&Q16 }
  },
  .is_final = true
};
const struct State Q16  = {
  .nextStates = {
    { .input='E', .state=&Q17 },
    { .input='A', .state=&Q25 }
  }
};
const struct State Q17  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q18  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q19  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q20  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q21  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q22  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q23  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q24  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q25  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q26  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q27  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q28  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q29  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q30  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q31  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q32  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q33  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q34  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q35  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q36  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q37  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q38  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q39  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q40  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q41  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q42  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q43  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q44  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q45  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q46  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q47  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q48  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q49  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q50  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q51  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q52  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q53  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q54  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q55  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q56  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q57  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q58  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};
const struct State Q59  = {
  .nextStates = {
    { .input=' ', .state=&Q }
  }
};

int main(int argc, char const *argv[])
{
  printf("%i\n", parser("SAYA "));
  return 0;
}

bool parser(char* input) {
  size_t inputLength = strlen(input);
  struct State currentState = Q0;
  for (int i = 0; i < inputLength; ++i)
  {
    size_t j = 0;
    bool valid = false;
    while(currentState.nextStates[j].state != NULL) {
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
