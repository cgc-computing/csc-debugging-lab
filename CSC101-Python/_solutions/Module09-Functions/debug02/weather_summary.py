# weather_summary.py
# Summarizes one day's weather from the morning low and the afternoon high.


def daily_range(high, low):
    """Return how many degrees the temperature rose during the day."""
    return high - low


def describe_range(degrees):
    """Return a short description of how much the temperature changed."""
    if degrees >= 20:
        return "a big swing"
    elif degrees >= 10:
        return "a moderate swing"
    else:
        return "a small swing"


morning = float(input("Morning temperature (F): "))
afternoon = float(input("Afternoon temperature (F): "))

swing = daily_range(afternoon, morning)

print()
print(f"Low:  {morning:.1f} F")
print(f"High: {afternoon:.1f} F")
print(f"The temperature rose {swing:.1f} degrees, {describe_range(swing)}.")
