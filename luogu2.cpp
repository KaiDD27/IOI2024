#include <algorithm>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

const int maxHP = 4;

struct CardPlayer {
  int nextId, prevId;
  list<char> lstCards;
  string roles;
  int HP = 4;
  bool equipedWeapon = false;
  bool killed = false;
} players[15];

queue<char> cardQue;
string recognizedRoles[15];
string winner;

void getCards(int currId, int count) {
  while (count--) {
    players[currId].lstCards.push_back(cardQue.front());
    if (cardQue.size() != 1)
      cardQue.pop();
  }
}

int gameOver() {
  if (players[1].HP == 0) {
    winner = "FP";
    return -1;
  } else {
    int currId = players[1].nextId;
    bool allFPDead = true;
    while (currId != 1) {
      if (players[currId].roles == "FP") {
        allFPDead = false;
        break;
      }
      currId = players[currId].nextId;
    }
    if (allFPDead == true) {
      return -1;
      winner = "MP";
    }
  }
  return 0;
}

int dead(int victimId, int attackerId) {
  if (gameOver() == -1)
    return -1;
  players[players[victimId].nextId].prevId = players[victimId].prevId;
  players[players[victimId].prevId].nextId = players[victimId].nextId;
  if (players[victimId].roles == "FP") {
    getCards(attackerId, 3);
  } else if (players[victimId].roles == "ZP" &&
             players[attackerId].roles == "MP") {
    players[attackerId].equipedWeapon = false;
    players[attackerId].lstCards.clear();
    return 2; // 主公杀了忠臣
  }
  return 1; // 受害者死亡了
}

int expressHostilityForKOrF(int currId, int distance) {
  int nextId = players[currId].nextId;
  if (distance == 1) {
    if (players[currId].roles == "MP" &&
        (recognizedRoles[nextId] == "FP" || recognizedRoles[nextId] == "LFP")) {
      return nextId;
    }

    if (players[currId].roles == "ZP" && recognizedRoles[nextId] == "FP") {
      recognizedRoles[currId] = "ZP";
      return nextId;
    }

    if (players[currId].roles == "FP" &&
        (recognizedRoles[nextId] == "MP" || recognizedRoles[nextId] == "ZP")) {
      recognizedRoles[currId] = "FP";
      return nextId;
    }
  } else {
    if (players[currId].roles == "FP") {
      recognizedRoles[currId] = "FP";
      return 1;
    } else {
      while (nextId != currId) {
        if (players[currId].roles == "MP" &&
            (recognizedRoles[nextId] == "FP" ||
             recognizedRoles[nextId] == "LFP")) {
          return nextId;
        }
        if (players[currId].roles == "ZP" && recognizedRoles[nextId] == "FP") {
          recognizedRoles[currId] = "ZP";
          return nextId;
        }
        nextId = players[nextId].nextId;
      }
    }
  }
  return 0;
}
bool expressGood(int currId, int effectTargetId) {
  if (players[currId].roles == "MP" &&
      (recognizedRoles[effectTargetId] == "ZP" ||
       recognizedRoles[effectTargetId] == "MP")) {
    return true;
  }

  if (players[currId].roles == "ZP" &&
      (recognizedRoles[effectTargetId] == "ZP" ||
       recognizedRoles[effectTargetId] == "MP")) {
    recognizedRoles[currId] = "ZP";
    return true;
  }

  if (players[currId].roles == "FP" &&
      recognizedRoles[effectTargetId] == "FP") {
    recognizedRoles[currId] = "FP";
    return true;
  }
  return false;
}
bool expressHostility(int currId, int playerExpressGood) {
  if (recognizedRoles[playerExpressGood] == "MP" &&
      players[currId].roles == "FP") {
    recognizedRoles[currId] = "FP";
    return true;
  }

  if (recognizedRoles[playerExpressGood] == "ZP" &&
      players[currId].roles == "FP") {
    recognizedRoles[currId] = "FP";
    return true;
  }

  if (recognizedRoles[playerExpressGood] == "FP" &&
      players[currId].roles == "ZP") {
    recognizedRoles[currId] = "ZP";
    return true;
  }

  if (recognizedRoles[playerExpressGood] == "FP" &&
      players[currId].roles == "MP") {
    recognizedRoles[currId] = "MP";
    return true;
  }

  if (recognizedRoles[playerExpressGood] == "LFP" &&
      players[currId].roles == "MP") {
    recognizedRoles[currId] = "MP";
    return true;
  }

  return false;
}
bool expressGoodRound(int effectTargetId, int attackedId);
bool expressHostilityRound(int playerExpressGood);

bool expressHostilityRound(int playerExpressGood) {
  int currId = players[playerExpressGood].nextId;
  while (currId != playerExpressGood) {
    auto it = find(players[currId].lstCards.begin(),
                   players[currId].lstCards.end(), 'J');
    if (it != players[currId].lstCards.end()) {
      if (expressHostility(currId, playerExpressGood) != 0) {
        players[currId].lstCards.erase(it);
        if (expressGoodRound(playerExpressGood, currId) == true)
          return false;
        else
          return true;
      }
    }
  }
  return false;
}

bool expressGoodRound(int effectTargetId, int attackedId) {
  int currId = players[attackedId].nextId;
  while (currId != attackedId) {
    auto it = find(players[currId].lstCards.begin(),
                   players[currId].lstCards.end(), 'J');
    if (it != players[currId].lstCards.end()) {
      if (expressGood(currId, effectTargetId) != 0) {
        players[currId].lstCards.erase(it);
        if (expressHostilityRound(currId) == true)
          return false;
        else
          return true;
      }
    }
    currId = players[currId].nextId;
  }
  return false;
}
void P(int currId, list<char>::iterator &it) {
  if (players[currId].HP < maxHP) {
    players[currId].HP += 1;
    // 删除这个节点，然后指向下一个节点
    it = players[currId].lstCards.erase(it);
  } else {
    it++;
  }
}

int minusHP(int victimId, int attackerId) {
  if (players[victimId].roles == "MP" && recognizedRoles[attackerId] == "") {
    recognizedRoles[attackerId] = "LFP";
  }
  if (--players[victimId].HP == 0) {
    auto it2 = find(players[victimId].lstCards.begin(),
                    players[victimId].lstCards.end(), 'P');
    if (it2 != players[victimId].lstCards.end()) {
      P(victimId, it2);
    } else {
      return dead(victimId, attackerId);
    }
  }
  return 0;
}

int forcedKillOrD(int victimId, int attackerId, char chCard) {
  auto it = find(players[victimId].lstCards.begin(),
                 players[victimId].lstCards.end(), chCard);
  if (it != players[victimId].lstCards.end()) {
    players[victimId].lstCards.erase(it);
    return 1000; // 轮到下一个出杀或者闪
  } else {
    return minusHP(victimId, attackerId);
  }
  return 0; // 自己掉血，但还没死。
}

int F(int currId) {
  int toFId = 0;
  toFId = expressHostilityForKOrF(currId, 11);
  int result = -100;
  if (toFId != 0) {
    // 看看是否有人出无懈可击

    if (toFId == 1) {
      recognizedRoles[currId] = "FP";
    } else if (recognizedRoles[toFId] == "FP" &&
               recognizedRoles[currId] != "MP") {
      recognizedRoles[currId] = "ZP";
    } else if (recognizedRoles[toFId] == "ZP") {
      recognizedRoles[currId] = "FP";
    }

    bool flagJ = expressGoodRound(toFId, currId);
    if (players[toFId].roles == "ZP" && players[currId].roles == "MP") {
      return minusHP(toFId, currId);
    }
    while (true || flagJ != true) {
      result = forcedKillOrD(toFId, currId, 'K');
      if (result == 0) // 接受决斗者扣血但没死。
        break;
      if (result == 1) // 接受决斗的死了。
        break;
      if (result == -1) // 游戏结束。
        return result;

      result = forcedKillOrD(currId, toFId, 'K');
      if (result == 0) // 发出决斗者扣血但没死。
        break;
      if (result == -1) // 游戏结束。
        return result;
      if (result == 1) // 发出决斗的死了。
        return result;
    }
  }
  return result;
}

int activeKill(int currId) {
  if (players[currId].killed == false ||
      players[currId].equipedWeapon == true) {

    int toKillId = 0;
    toKillId = expressHostilityForKOrF(currId, 1);
    if (toKillId != 0) {
      players[currId].killed = true;
      return forcedKillOrD(toKillId, currId, 'D');
    }
  }
  return 10000;
}
int NorW(int attackerId, list<char>::iterator &it, char chCard) {
  int currId = players[attackerId].nextId;
  while (currId != attackerId) {
    if (expressGoodRound(currId, attackerId) == false) {
      int result = -100;
      result = forcedKillOrD(currId, attackerId, chCard);
      if (result == -1)
        return -1;
    }
    currId = players[currId].nextId;
  }
  it = players[attackerId].lstCards.erase(it);
  return 0;
}

int gameRound(int currId) {
  getCards(currId, 2);

  // 恢复killed 状态
  players[currId].killed = false;
  int result;
  auto it = players[currId].lstCards.begin();
  while (!players[currId].lstCards.empty() &&
         it != players[currId].lstCards.end()) {
    switch (*it) {
    case 'P':
      // 桃
      P(currId, it);
      break;
    case 'K':
      // 杀
      result = activeKill(currId);
      if (result == -1) {
        it = players[currId].lstCards.erase(it);
        return -1;
      }
      if (result == 10000) {
        it++;
      } else if (result == 2) {
        // MP手牌已清空，所以不做任何操作，等待发现手牌已空，轮到下一个玩家。
      } else {
        it = players[currId].lstCards.erase(it);
      }

      break;
    case 'D':
      it++;
      break;
    case 'F':
      //
      result = F(currId);
      if (result == -1) {
        it = players[currId].lstCards.erase(it);
        return -1;
      }
      if (result == 1) { // currId dead 无法继续出牌
        it = players[currId].lstCards.erase(it);
        return 1;
      }
      if (result == 0) {
        it = players[currId].lstCards.erase(it);
      } else if (result == 2) {
        // MP手牌已清空，所以不做任何操作，等待发现手牌已空，轮到下一个玩家。
      } else {
        it++;
      }
      break;
    case 'N':
      //
      result = NorW(currId, it, 'K');
      if (result == -1) {
        it = players[currId].lstCards.erase(it);
        return -1;
      }
      break;
    case 'W':
      //
      result = NorW(currId, it, 'D');
      if (result == -1) {
        it = players[currId].lstCards.erase(it);
        return -1;
      }
      break;
    case 'J':
      it++;
      break;
    case 'Z':
      //
      players[currId].equipedWeapon = true;
      it = players[currId].lstCards.erase(it);
      break;
    }
  }
  return 0;
}

int main() {
  int n, m;
  cin >> n >> m;

  // 初始化玩家角色，手牌，前后玩家。
  for (int i = 1; i <= n; i++) {
    cin >> players[i].roles;
    char chIn;
    for (int j = 1; j <= 4; j++) {
      cin >> chIn;
      players[i].lstCards.push_back(chIn);
    }
    players[i].prevId = i - 1;
    players[i].nextId = i + 1;
    if (players[i].prevId == 0)
      players[i].prevId = n;
    if (players[i].nextId == n + 1)
      players[i].nextId = 1;
  }

  recognizedRoles[1] = "MP";

  // 初始化牌堆
  for (int i = 1; i <= m; i++) {
    char chIn;
    cin >> chIn;
    cardQue.push(chIn);
  }

  int currId = 1;
  while (true) {
    if (gameRound(currId) == -1)
      break; // gameover

    // 判断游戏是否结束了
    //

    currId = players[currId].nextId;
  }

  // 输出结果
  cout << winner << endl;
  for (int i = 1; i <= n; i++) {
    if (players[i].HP == 0)
      cout << "DEAD" << endl;
    else {
      for (auto &card : players[i].lstCards) {
        cout << card << " ";
      }
      cout << endl;
    }
  }
  return 0;
}