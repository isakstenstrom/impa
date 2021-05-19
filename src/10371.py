TZ = {
    "UTC": 0,
    "GMT": 0,
    "BST": 1,
    "IST": 1,
    "WET": 0,
    "WEST": 1,
    "CET": 1,
    "CEST": 2,
    "EET": 2,
    "EEST": 3,
    "MSK": 3,
    "MSD": 4,
    "AST": -4,
    "ADT": -3,
    "NST": -3.5,
    "NDT": -2.5,
    "EST": -5,
    "EDT": -4,
    "CST": -6,
    "CDT": -5,
    "MST": -7,
    "MDT": -6,
    "PST": -8,
    "PDT": -7,
    "HST": -10,
    "AKST": -9,
    "AKDT": -8,
    "AEST": 10,
    "AEDT": 11,
    "ACST": 9.5,
    "ACDT": 10.5,
    "AWST": 8,
}

def toMinutes(times):
    if times == "midnight":
        return 0
    if times == "noon":
        return 720
    (time, am_pm) = times.split()
    (hour, minute) = time.split(":")
    if hour == "12":
        hour = "0"
    minutes = 0
    if am_pm == "p.m.":
        minutes += 720
    minutes += int(hour) * 60
    minutes += int(minute)
    return minutes

def toDumbFormat(minutes):
    minutes = minutes % 1440
    if minutes == 0:
        return "midnight"
    if minutes == 720:
        return "noon"
    am_pm = "a.m."
    if minutes > 720:
        am_pm = "p.m."
        minutes -= 720
    hour = str(minutes//60)
    if hour == "0":
        hour = "12"
    return hour + ":" + str(minutes % 60).zfill(2) + " " + am_pm


N = input()
for i in range(int(N)):
    timestamps = input().split()
    minutes = 0
    if len(timestamps) == 3:
        minutes = toMinutes(timestamps[0])
    else:
        minutes = toMinutes(timestamps[0] + " " + timestamps[1])
    
    timediff = TZ[timestamps[-1]] - TZ[timestamps[-2]]

    minutes += int(timediff*60)

    print(toDumbFormat(minutes))