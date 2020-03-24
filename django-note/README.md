# DJango Notes

---

**Create django project**
```sh
$ django-admin startproject <projectname>
``` 

**Create app**
```sh
$ python manage.py startapp <appname>
```

Configure app with `settings.py` Array `INSTALLED_APPS`, If app name is main
```python
INSTALLED_APPS = [
    'main.apps.MainConfig',
    'django.contrib.admin',
    ...
]
```

**Start server**
```sh
$ python manage.py runserver
```

**Create super user (Username Email Password)**
```sh
$ python manage.py createsuperuser
```


#### Create Database

Create the models in models.py file inside the app folder `Classes -> Table` **&** `Variable -> Field`

**Create migration files**
```sh
$ python manage.py makemigrations <appname>
```

**Apply migrations**
```sh
$ python manage.py migrate
```

#### Django Urls

```python
urlpatterns = [
	path('add-question/', views.add_question, name='add-question'),
	re_path(r'^api/.*$', views.api, name='api'), 
]
```


#### Url in Template file

main is `app_name` variable in urls file

```python
app_name = 'main'
urlpatterns = [
		path('add-question/', views.question, name='question'),
		re_path(r'^api/.*$', views.index, name='index'), 
	]
```

```html
{% url 'main:index' %} and function with parameter {% url 'main:question' question.id %}
```

#### managing static files

Request url for static files
```python
STATIC_URL = '/static/'
```

static file directories
```python
	STATICFILES_DIRS = [
	    'static' # /project-root/static/
	]
```

