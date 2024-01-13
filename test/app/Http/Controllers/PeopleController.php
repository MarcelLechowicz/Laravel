<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\People;

class PeopleController extends Controller
{
    public function index()
    {
        return People::all();
    }
    
    public function store(Request $request)
    {
        $people = People::create($request->all());
    
        return response()->json($people, 201);
    }
    
    public function show(People $people)
    {
        return response()->json($people);
    }
    
    public function update(Request $request, People $people)
    {
        $people->update($request->all());
    
        return response()->json($people);
    }
    
    public function destroy(People $people)
    {
        $people->delete();
    
        return response()->json(null, 204);
    }
}
