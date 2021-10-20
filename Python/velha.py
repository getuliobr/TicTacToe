from random import randint

class Game:
  board = [
    7, 8, 9,
    4, 5, 6,
    1, 2, 3
  ]

  player = [None, None]

  rounds = 0

  starter = 0

  def __init__(self):
    self.__pickSymbol()
    self.__pickStarterPlayer()
    self.__start()
    

  def __showGame(self):
    for y in range(3):
      print(f' {self.board[y*3]} | {self.board[y*3 + 1]} | {self.board[y*3 + 2]}')
      if y != 2:
        print('-----------')

  def __checkWinner(self):
    for y in range(3):
      if self.board[y*3] == self.board[y*3 + 1] and self.board[y*3 + 1] == self.board[y*3 + 2]:
        return self.board[y*3]

    for x in range(3):
      if self.board[x] == self.board[x + 3] and self.board[x + 3] == self.board[x + 6]:
        return self.board[x]
    
    if self.board[0] == self.board[4] and self.board[4] == self.board[8]:
      return self.board[0]

    if self.board[2] == self.board[4] and self.board[4] == self.board[6]:
      return self.board[0]
    
    return False

  def __pickSymbol(self):
    j1 = input('Qual o seu simbolo jogador 1? ')
    j2 = input('Qual o seu simbolo jogador 2? ')
    while j2 == j1:
      j2 = input('Seu simbolo tem que ser diferente do jogador 1, qual o seu simbolo jogador 2? ')
    self.player = [j1, j2]

  def __pickStarterPlayer(self):
    self.starter = randint(0, 1)

  def __treatPosition(self, pos):
    posList = [7, 8, 9, 4, 5, 6, 1, 2, 3]
    return posList[int(pos) - 1]

  def __start(self):
    print(f'O jogador {self.player[self.starter]} começa!')

    winner = False
    while not winner and self.rounds != 9:
      self.__showGame()
      currPlayer = self.player[(self.rounds + self.starter) % 2]
      pos = self.__treatPosition(input(f'Jogador {currPlayer} marcar qual posicao? ')) - 1

      while self.board[pos] in self.player:
        pos = self.__treatPosition(input(f'A posicao ja esta ocupada, jogador {currPlayer}, quer marcar qual posicao? ')) - 1

      self.board[pos] = currPlayer


      winner = self.__checkWinner()
      self.rounds += 1

    if winner:
      print(f'O jogador {winner} ganhou!')
    else:
      print('Deu velha')


keepPlaying = True
while keepPlaying:
  Game()
  keepPlaying = True if input('Deseja jogar de novo? (s)im ou (n)ao ') == 's' else False