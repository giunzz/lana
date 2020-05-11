import pygame
import random
import sys
from pygame.locals import *

# Khoi dong he thong
pygame.init()

DI_LEN = (-1, 0)
DI_XUONG = (1, 0)
QUA_TRAI = (0, -1)
QUA_PHAI = (0, 1)

class Luoi:
    def __init__(self, chieungang, chieudoc, ovuong):
        self.ngang = chieungang
        self.doc = chieudoc
        self.ovuong = ovuong

        # Tao man hinh tro choi
        self.manhinh = pygame.display.set_mode((chieungang, chieudoc), 0, 32)

        # Mat phang
        self.matphang = pygame.Surface(self.manhinh.get_size())
        self.matphang = self.matphang.convert()
        self.matphang.fill((255, 255, 255))

        # Dong ho
        self.dongho = pygame.time.Clock()

        # Cho phep nguoi dung de mot nut
        pygame.key.set_repeat(1, 40)

        self.manhinh.blit(self.matphang, (0, 0))

    def xoa_luoi(self):
        self.matphang.fill((255, 255, 255))
        self.manhinh.blit(self.matphang, (0, 0))

    def ve_diem(self, vitri, mau):
        diem = pygame.Rect((vitri[1], vitri[0]), (self.ovuong, self.ovuong))
        pygame.draw.rect(self.matphang, mau, diem)

    def chuyen_dong_ho(self):
        self.manhinh.blit(self.matphang, (0, 0))
        pygame.display.update()
        self.dongho.tick(20)

class Ran:
    def __init__(self, chieungang, chieudoc, ovuong, huong_di):
        self.vitri = []
        self.vitri.append((chieudoc / 2, chieungang/2))
        self.chieungang = chieungang
        self.chieudoc = chieudoc
        self.ovuong = ovuong
        self.huong_di = huong_di
        self.mau_ran = (0, 0, 0)
        self.chieudai = 10

    def ket_thuc(self):
        self.chieudai = 10
        self.vitri = []
        self.vitri.append((self.chieudoc /2, self.chieungang / 2))

    def di_chuyen(self):
        dong, cot = self.huong_di
        dong_tiep = (self.vitri[0][0] + dong * self.ovuong) % self.chieudoc
        cot_tiep = (self.vitri[0][1] + cot * self.ovuong) % self.chieungang
        vitri_tiep = (dong_tiep, cot_tiep)

        if (len(self.vitri) == self.chieudai):
            self.vitri.pop()

        self.vitri = [vitri_tiep] + self.vitri

        if (vitri_tiep in self.vitri[1:]):
            self.ket_thuc()

    def ve(self, luoi):
        for v in self.vitri:
            luoi.ve_diem(v, self.mau_ran)

    def chuyenhuong(self, huong):
        self.huong_di = huong

    def an(self, thucan):
        if (thucan.lay_vitri() == self.vitri[0]):
            self.chieudai += 1
            thucan.xuat_hien_ngau_nhien()

class ThucAn:
    def __init__(self, chieu_ngang, chieu_doc, ovuong):
        self.vitri = (0, 0)
        self.mau = (255, 0, 0)
        self.chieu_ngang = chieu_ngang
        self.chieu_doc = chieu_doc
        self.ovuong = ovuong
        self.xuat_hien_ngau_nhien()

    def ve(self, luoi):
        luoi.ve_diem(self.vitri, self.mau)

    def xuat_hien_ngau_nhien(self):
        dong = random.randint(0, self.chieu_doc / self.ovuong - 1) * self.ovuong
        cot = random.randint(0, self.chieu_ngang / self.ovuong - 1) * self.ovuong
        self.vitri = (dong, cot)

    def lay_vitri(self):
        return self.vitri

luoi = Luoi(640, 480, 10)
ran = Ran(640, 480, 10, QUA_PHAI)
thucans = [ThucAn(640, 480, 10) for i in range(10)]

while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == KEYDOWN:
            if event.key == K_UP:
                ran.chuyenhuong(DI_LEN)
            elif event.key == K_DOWN:
                ran.chuyenhuong(DI_XUONG)
            elif event.key == K_LEFT:
                ran.chuyenhuong(QUA_TRAI)
            elif event.key == K_RIGHT:
                ran.chuyenhuong(QUA_PHAI)

    luoi.xoa_luoi()
    ran.ve(luoi)
    for thucan in thucans:
        thucan.ve(luoi)
        thucan.ve(luoi)
        ran.an(thucan)
    luoi.chuyen_dong_ho()
    ran.di_chuyen()