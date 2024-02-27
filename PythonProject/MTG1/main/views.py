from django.shortcuts import render


def genre_catalog(request):
    cinema_url = '/cinema/'
    theatre_url = '/theatre/'
    # drama_url = '/drama/'

    return render(request, 'index.html', {'action_url': cinema_url, 'comedy_url': theatre_url})

