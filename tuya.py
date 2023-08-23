# index.py
import tinytuya
import argparse
import time

#init parser
parser = argparse.ArgumentParser()
parser.add_argument("--lampu")
parser.add_argument("--warna")
parser.add_argument("--cerah")

#init tuya device
lampu1 = tinytuya.BulbDevice('xxx', '192.168.0.xxx', 'xxx') #deviceid, ipAddress, localKey
lampu2 = tinytuya.BulbDevice('xxx', '192.168.0.xxx', 'xxx') #deviceid, ipAddress, localKey
lampu1.set_version(3.3)
lampu2.set_version(3.3)

def main():
    args = parser.parse_args()
    warna_lampu = args.warna
    kondisi_lampu = int(args.lampu)
    cerah_lampu = int(args.cerah)
    warnasplit = warna_lampu.split(',')
    r = int(warnasplit[0])
    g = int(warnasplit[1])
    b = int(warnasplit[2])
    
    if (kondisi_lampu == 1) :
        lampu1.turn_on()
        lampu2.turn_on()
        lampu1.set_colour(r,g,b)
        lampu2.set_colour(r,g,b)
        lampu1.set_brightness_percentage(cerah_lampu)
        lampu2.set_brightness_percentage(cerah_lampu)
        kondisi_lampu = 2
    elif kondisi_lampu == 0 :
        lampu1.turn_off()
        lampu2.turn_off()

if __name__ == "__main__" :
    main()
