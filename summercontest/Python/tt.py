import pygame
pygame.init()
dis = pygame.display.set_mode((400,300)) #kích thước 400x300
pygame.display.update()
game_over = False #Biến đánh dấu sự kiện kết thúc game
while not game_over:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game_over = True
            #failed
pygame.quit()
quit()
