from django.shortcuts import render
from .models import Event

def events_catalog(request):
    events = Event.objects.exclude(title__isnull=True).exclude(title__exact='None inf')
    unique_events = list(set(events))
    return render(request, "main/index.html", {"events": unique_events})

def event_detail(request, event_id):
    event = Event.objects.get(id=event_id)
    return render(request, 'main/event_details.html', {'event': event})